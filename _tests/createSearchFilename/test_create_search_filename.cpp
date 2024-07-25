#include "docker_search_test.hpp"
#include "docker_search.hpp"
#include "musgravite.hpp"



void TestCreateSearchFilenameSuccess() {
    DockerSearchTestFixture fixture;
    std::string validPath = "./test_directory"; 
    fixture.test.callDefinePath(fixture.ds, validPath); 
    
    std::string name = "testfile";
    fixture.test.callCreateSearchFilename(fixture.ds, name);
    
    std::string tempFilename = fixture.test.getPath(fixture.ds) + "/temp_" + name + ".txt";
    ASSERT_TRUE(std::filesystem::exists(tempFilename));
    
    std::filesystem::remove(tempFilename);
    std::filesystem::remove_all(validPath);
}



void TestCreateSearchFilenameNoPath() {
    DockerSearchTestFixture fixture;
    std::string emptyPath = "";
    fixture.test.callDefinePath(fixture.ds, emptyPath);
    std::string name = "testfile";
    
    ASSERT_THROW(fixture.test.callCreateSearchFilename(fixture.ds, name), std::runtime_error);
}



void TestCreateSearchFilenameInvalidPath() {
    DockerSearchTestFixture fixture;
    std::string invalidPath = "/invalid/path";
    fixture.test.callDefinePath(fixture.ds, invalidPath);
    std::string name = "testfile";
    
    ASSERT_THROW(fixture.test.callCreateSearchFilename(fixture.ds, name), std::runtime_error);
}



void TestCreateSearchFilenameEmptyName() {
    DockerSearchTestFixture fixture;

    std::string name = "";

    ASSERT_THROW(fixture.test.callCreateSearchFilename(fixture.ds, name), std::runtime_error);
}