#include "tagify_test.hpp"



void TagifyTest::callConvertToLower(Tagify& ds, std::string& name) {
    ds.convertToLower(name);
}



void TagifyTest::callCreateSearchFilename(Tagify& ds, std::string& name) {
    ds.createSearchFilename(name);
}



void TagifyTest::callSearchNameInDockerhub(Tagify& ds, std::string& name) {
    ds.searchNameInDockerhub(name);
}



std::string TagifyTest::callMountUrl(Tagify& ds, std::string& name) {
    return ds.mountUrl(name);
}



void TagifyTest::callRenameSearchFile(Tagify& ds, std::string& name, std::string& tempFilename) {
    ds.renameSearchFile(name, tempFilename);
}



std::string TagifyTest::callFetchDataFromUrl(Tagify& ds, const std::string& url) {
    return ds.fetchDataFromUrl(url);
}



Json::Value TagifyTest::callParseJson(Tagify& ds, const std::string& jsonData) {
    return ds.parseJson(jsonData);
}



void TagifyTest::callProcessTags(Tagify& ds, const Json::Value& jsonResponse, std::ofstream& tempFile) {
    ds.processTags(jsonResponse, tempFile);
}



std::string TagifyTest::callGetNextPageUrl(Tagify& ds, const Json::Value& jsonResponse) {
    return ds.getNextPageUrl(jsonResponse);
}



void TagifyTest::callSortFile(Tagify& ds, const std::string& filename) {
    ds.sortFile(filename);
}



void TagifyTest::callDefinePath(Tagify& ds, std::string& path) {
    ds.define_path(path);
}



std::string TagifyTest::getPath(Tagify& ds) {
    return ds.getPath();
}