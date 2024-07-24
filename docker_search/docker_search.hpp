#ifndef DOCKER_SEARCH_HPP
#define DOCKER_SEARCH_HPP



#include "_include.hpp"



class DockerSearch {
    private:
        std::string path;
        std::ofstream fileStream;

        void convertToLower(std::string& name);
        void createSearchFilename(std::string& name);
        void searchNameInDockerhub(std::string& name);

        std::string mountUrl(std::string& name);
    public:
        void define_path(std::string& path);
        void start_search(std::string& name);
};



#endif