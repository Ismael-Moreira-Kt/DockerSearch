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
    std::string pathToFile = this -> path + "/" + filename;


    try {
        fs::create_directories(
            fs::path(this -> path)
            .parent_path()
        );
        std::ofstream file(pathToFile);

        if (!file) {
            throw std::runtime_error("Failed to create file: " + pathToFile);
        }

        file.close();
    } catch (const std::runtime_error& error) {
        throw std::runtime_error(error.what());
    }
}