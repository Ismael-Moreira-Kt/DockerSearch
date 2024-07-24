#ifndef DOCKER_SEARCH_HPP
#define DOCKER_SEARCH_HPP



#include "_include.hpp"



class DockerSearch {
    private:
        std::string path;
        std::ofstream fileStream;
    public:
        void define_path(std::string& path);
};



#endif