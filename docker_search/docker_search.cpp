#include "docker_search.hpp"



namespace fs = std::filesystem;



size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}



void DockerSearch::define_path(std::string& path) {
    this->path = path;
}



void DockerSearch::start_search(std::string& name) {
    if (this->path.empty()) {
        this->path = ".";
    }

    if (name.empty()) {
        throw std::runtime_error("Name cannot be empty.");
    }

    try {
        this->convertToLower(name);
        this->createSearchFilename(name);
        this->searchNameInDockerhub(name);
    } catch(const std::runtime_error& error) {
        std::cerr << "Search process stopped: " << error.what() << std::endl;
    }
}



void DockerSearch::convertToLower(std::string& name) {
    std::transform(
        name.begin(), name.end(), name.begin(),
        [](unsigned char c) -> char {
            return std::tolower(c);
        }
    );
}



void DockerSearch::createSearchFilename(std::string& name) {
    std::string filename = name + ".txt";
    std::string tempFilename = this->path + "/temp_" + filename;

    try {
        fs::create_directories(this->path);

        std::ofstream tempFile(tempFilename);
        if (!tempFile) {
            throw std::runtime_error("Failed to create temporary file: " + tempFilename);
        }

        tempFile.close();
    } catch (const std::exception& error) {
        throw std::runtime_error("Failed to create file: " + std::string(error.what()));
    }
}



void DockerSearch::searchNameInDockerhub(std::string& name) {
    std::string jsonData;
    Json::Value jsonResponse;
    std::string nextPageUrl = this->mountUrl(name);
    std::string tempFilename = this->path + "/temp_" + name + ".txt";

    try {
        std::ofstream tempFile(tempFilename, std::ios::app);
        if (!tempFile) {
            throw std::runtime_error("Failed to open temporary file: " + tempFilename);
        }

        do {
            jsonData = this->fetchDataFromUrl(nextPageUrl);
            jsonResponse = this->parseJson(jsonData);
        
            this->processTags(jsonResponse, tempFile);
            nextPageUrl = this->getNextPageUrl(jsonResponse);

        } while (!nextPageUrl.empty());

        tempFile.close();
        this->sortFile(tempFilename);
        this->renameSearchFile(name, tempFilename);
    } catch (const std::exception& error) {
        std::cerr << "Error processing the response: " << error.what() << std::endl;
        std::remove(tempFilename.c_str());
    }
}



std::string DockerSearch::mountUrl(std::string& name) {
    return "https://hub.docker.com/v2/repositories/library/" + name + "/tags/";
}



void DockerSearch::renameSearchFile(std::string& name, std::string& tempFilename) {
    try {
        std::string finalFilename = this->path + "/" + name + ".txt";
        if (std::rename(tempFilename.c_str(), finalFilename.c_str()) != 0) {
            throw std::runtime_error("Failed to rename file.");
        }
    } catch (const std::exception& error) {
        std::cerr << "Error renaming the temporary file: " << error.what() << std::endl;
    }
}



std::string DockerSearch::fetchDataFromUrl(const std::string& url) {
    std::string readBuffer;
    CURL* curl;
    CURLcode response;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        response = curl_easy_perform(curl);

        if (response != CURLE_OK) {
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            throw std::runtime_error("Failed to fetch data: " + std::string(curl_easy_strerror(response)));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return readBuffer;
}



Json::Value DockerSearch::parseJson(const std::string& jsonData) {
    Json::CharReaderBuilder readerBuilder;
    Json::Value jsonResponse;

    std::istringstream ss(jsonData);
    std::string errs;

    if (!Json::parseFromStream(readerBuilder, ss, &jsonResponse, &errs)) {
        throw std::runtime_error("Failed to parse JSON: " + errs);
    }
    
    return jsonResponse;
}



void DockerSearch::processTags(const Json::Value& jsonResponse, std::ofstream& tempFile) {
    if (!jsonResponse.isMember("results")) {
        throw std::runtime_error("JSON does not contain 'results' field.");
    }

    const Json::Value& tagsArray = jsonResponse["results"];

    if (!tagsArray.isArray()) {
        throw std::runtime_error("'results' field is not an array.");
    }

    for (const auto& tag : tagsArray) {
        std::string tagName = tag["name"].asString();
        tempFile << tagName << std::endl;
    }
}



std::string DockerSearch::getNextPageUrl(const Json::Value& jsonResponse) {
    if (jsonResponse.isMember("next") && !jsonResponse["next"].asString().empty()) {
        return jsonResponse["next"].asString();
    }

    return "";
}



void DockerSearch::sortFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for sorting: " + filename);
    }

    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    std::sort(lines.begin(), lines.end());
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        throw std::runtime_error("Failed to open file for writing sorted content: " + filename);
    }

    for (const auto& sortedLine : lines) {
        outFile << sortedLine << std::endl;
    }

    outFile.close();
}