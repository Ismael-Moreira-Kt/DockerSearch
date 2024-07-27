#ifndef tagify_HPP
#define tagify_HPP



#include "_include.hpp"



class Tagify {
    private:
        std::string path;
        std::ofstream fileStream;

        void convertToLower(std::string& name);
        void createSearchFilename(std::string& name);
        void searchNameInDockerhub(std::string& name);

        std::string mountUrl(std::string& name);
        void renameSearchFile(std::string &name, std::string &tempFilename);
        std::string fetchDataFromUrl(const std::string& url);
        Json::Value parseJson(const std::string& jsonData);
        void processTags(const Json::Value& jsonResponse, std::ofstream& tempFile);
        std::string getNextPageUrl(const Json::Value& jsonResponse);
        void sortFile(const std::string& filename);

        std::string getPath();

        friend class TagifyTest;
    public:
        void define_path(std::string& path);
        void start_search(std::string& name);
};



size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);



#endif