#include "musgravite.hpp"
#include "docker_search_test.hpp"
#include "docker_search.hpp"



void TestConvertToLowerPositive() {
    DockerSearchTestFixture fixture;

    std::string name = "SOME NAME";
    fixture.test.callConvertToLower(fixture.ds, name);

    ASSERT_EQUAL(name, "some name");
}



void TestConvertToLowerAlreadyLowercase() {
    DockerSearchTestFixture fixture;

    std::string name = "already lowercase";
    fixture.test.callConvertToLower(fixture.ds, name);

    ASSERT_EQUAL(name, "already lowercase");
}