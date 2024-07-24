#include "docker_search.hpp"



namespace fs = std::filesystem;



void DockerSearch::define_path(std::string& path) {
    this -> path = path;
}



void DockerSearch::start_search(std::string& name) {
    if (this -> path.empty()) {
        this -> path = ".";
    }

    if (name.empty()) {
        throw std::runtime_error("Name cannot be empty.");
    }

    try {
        this -> convertToLower(name);
        this -> createSearchFilename(name);
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
    std::string pathToFile = this->path + "/" + filename;
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