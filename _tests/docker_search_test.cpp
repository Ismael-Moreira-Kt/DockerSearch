#include "docker_search.hpp"



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