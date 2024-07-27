#ifndef tagify_TEST_HPP
#define tagify_TEST_HPP



#include "tagify.hpp"



class TagifyTest {
    public:
        void callConvertToLower(Tagify& ds, std::string& name);
        void callCreateSearchFilename(Tagify& ds, std::string& name);
        void callSearchNameInDockerhub(Tagify& ds, std::string& name);
        std::string callMountUrl(Tagify& ds, std::string& name);
        void callRenameSearchFile(Tagify& ds, std::string& name, std::string& tempFilename);
        std::string callFetchDataFromUrl(Tagify& ds, const std::string& url);
        Json::Value callParseJson(Tagify& ds, const std::string& jsonData);
        void callProcessTags(Tagify& ds, const Json::Value& jsonResponse, std::ofstream& tempFile);
        std::string callGetNextPageUrl(Tagify& ds, const Json::Value& jsonResponse);
        void callSortFile(Tagify& ds, const std::string& filename);
        void callDefinePath(Tagify& ds, std::string& path);
        std::string getPath(Tagify& ds);
};



class TagifyTestFixture {
    public:
        Tagify ds;
        TagifyTest test;
};



#endif