#include "tests.hpp"
#include "musgravite.hpp"
#include "tagify_test.hpp"



int main() {
    MusgraviteRunner musgravite;


    ADD_TEST(musgravite, "Tagify convertToLower Tests", TestConvertToLowerPositive);
    ADD_TEST(musgravite, "Tagify convertToLower Tests", TestConvertToLowerAlreadyLowercase);
    ADD_TEST(musgravite, "Tagify convertToLower Tests", TestConvertToLowerEmpty);
    ADD_TEST(musgravite, "Tagify convertToLower Tests", TestConvertToLowerMixedCase);
    ADD_TEST(musgravite, "Tagify convertToLower Tests", TestConvertToLowerNonAlphabetic);

    ADD_TEST(musgravite, "Tagify createSearchFile Tests", TestCreateSearchFilenameSuccess);
    ADD_TEST(musgravite, "Tagify createSearchFile Tests", TestCreateSearchFilenameNoPath);
    ADD_TEST(musgravite, "Tagify createSearchFile Tests", TestCreateSearchFilenameInvalidPath);
    ADD_TEST(musgravite, "Tagify createSearchFile Tests", TestCreateSearchFilenameEmptyName);
    ADD_TEST(musgravite, "Tagify createSearchFile Tests", TestCreateSearchFilenameLongName);


    musgravite.runAllTests();
    return 0;
}