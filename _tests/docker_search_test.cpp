#include "docker_search_test.hpp"



void DockerSearchTest::callConvertToLower(DockerSearch& ds, std::string& name) {
    ds.convertToLower(name);
}



void DockerSearchTest::callCreateSearchFilename(DockerSearch& ds, std::string& name) {
    ds.createSearchFilename(name);
}



void DockerSearchTest::callSearchNameInDockerhub(DockerSearch& ds, std::string& name) {
    ds.searchNameInDockerhub(name);
}



std::string DockerSearchTest::callMountUrl(DockerSearch& ds, std::string& name) {
    return ds.mountUrl(name);
}



void DockerSearchTest::callRenameSearchFile(DockerSearch& ds, std::string& name, std::string& tempFilename) {
    ds.renameSearchFile(name, tempFilename);
}



std::string DockerSearchTest::callFetchDataFromUrl(DockerSearch& ds, const std::string& url) {
    return ds.fetchDataFromUrl(url);
}



Json::Value DockerSearchTest::callParseJson(DockerSearch& ds, const std::string& jsonData) {
    return ds.parseJson(jsonData);
}



void DockerSearchTest::callProcessTags(DockerSearch& ds, const Json::Value& jsonResponse, std::ofstream& tempFile) {
    ds.processTags(jsonResponse, tempFile);
}



std::string DockerSearchTest::callGetNextPageUrl(DockerSearch& ds, const Json::Value& jsonResponse) {
    return ds.getNextPageUrl(jsonResponse);
}



void DockerSearchTest::callSortFile(DockerSearch& ds, const std::string& filename) {
    ds.sortFile(filename);
}



void DockerSearchTest::callDefinePath(DockerSearch& ds, std::string& path) {
    ds.define_path(path);
}



std::string DockerSearchTest::getPath(DockerSearch& ds) {
    return ds.getPath();
}