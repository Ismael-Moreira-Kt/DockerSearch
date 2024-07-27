#include "musgravite.hpp"
#include "tagify_test.hpp"
#include "tagify.hpp"



void TestConvertToLowerPositive() {
    TagifyTestFixture fixture;

    std::string name = "SOME NAME";
    fixture.test.callConvertToLower(fixture.ds, name);

    ASSERT_EQUAL(name, "some name");
}



void TestConvertToLowerAlreadyLowercase() {
    TagifyTestFixture fixture;

    std::string name = "already lowercase";
    fixture.test.callConvertToLower(fixture.ds, name);

    ASSERT_EQUAL(name, "already lowercase");
}



void TestConvertToLowerEmpty() {
    TagifyTestFixture fixture;

    std::string name = "";
    fixture.test.callConvertToLower(fixture.ds, name);

    ASSERT_EQUAL(name, "");
}



void TestConvertToLowerMixedCase() {
    TagifyTestFixture fixture;
    
    std::string name = "MiXeD CaSe";
    fixture.test.callConvertToLower(fixture.ds, name);
    
    ASSERT_EQUAL(name, "mixed case");
}



void TestConvertToLowerNonAlphabetic() {
    TagifyTestFixture fixture;
    
    std::string name = "123456 !@#$%";
    fixture.test.callConvertToLower(fixture.ds, name);
    
    ASSERT_EQUAL(name, "123456 !@#$%");
}