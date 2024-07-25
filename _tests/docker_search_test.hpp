#ifndef DOCKER_SEARCH_TEST_HPP
#define DOCKER_SEARCH_TEST_HPP



#include "docker_search.hpp"



class DockerSearchTest {
    public:
        void callConvertToLower(DockerSearch& ds, std::string& name);
        void callCreateSearchFilename(DockerSearch& ds, std::string& name);
        void callSearchNameInDockerhub(DockerSearch& ds, std::string& name);
        std::string callMountUrl(DockerSearch& ds, std::string& name);
        void callRenameSearchFile(DockerSearch& ds, std::string& name, std::string& tempFilename);
        std::string callFetchDataFromUrl(DockerSearch& ds, const std::string& url);
        Json::Value callParseJson(DockerSearch& ds, const std::string& jsonData);
        void callProcessTags(DockerSearch& ds, const Json::Value& jsonResponse, std::ofstream& tempFile);
        std::string callGetNextPageUrl(DockerSearch& ds, const Json::Value& jsonResponse);
        void callSortFile(DockerSearch& ds, const std::string& filename);
        void callDefinePath(DockerSearch& ds, std::string& path);
        std::string getPath(DockerSearch& ds);
};



class DockerSearchTestFixture {
    public:
        DockerSearch ds;
        DockerSearchTest test;
};



#endif