#include "gtest/gtest.h"
#include "removeByIndex.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//Komenda do zbudowania aplikacji z testami google:
//g++ -I..\googletest-release-1.6.0\googletest-release-1.6.0\include -L..\googletest-release-1.6.0\googletest-release-1.6.0\build main.cpp removeByIndex.cpp removeByIndexTests.cpp -lgtest