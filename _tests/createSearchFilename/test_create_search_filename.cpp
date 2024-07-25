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