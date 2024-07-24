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