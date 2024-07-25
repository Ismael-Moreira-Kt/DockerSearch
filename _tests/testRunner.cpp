#include "tests.hpp"
#include "musgravite.hpp"
#include "docker_search_test.hpp"



int main() {
    MusgraviteRunner musgravite;


    ADD_TEST(musgravite, "DockerSearch convertToLower Tests", TestConvertToLowerPositive);
    ADD_TEST(musgravite, "DockerSearch convertToLower Tests", TestConvertToLowerAlreadyLowercase);
    ADD_TEST(musgravite, "DockerSearch convertToLower Tests", TestConvertToLowerEmpty);
    ADD_TEST(musgravite, "DockerSearch convertToLower Tests", TestConvertToLowerMixedCase);
    ADD_TEST(musgravite, "DockerSearch convertToLower Tests", TestConvertToLowerNonAlphabetic);


    musgravite.runAllTests();
    return 0;
}