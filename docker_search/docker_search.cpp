#include "docker_search.hpp"



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

    } catch(const std::runtime_error& error) {
        std::cerr << "Search process stopped: " << error.what() << std::endl;
    }
}