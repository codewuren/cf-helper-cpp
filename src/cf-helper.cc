#include "cf-helper.h"

// print help info
void cfHelper::help() {
    std::cout << "help()" << std::endl;
}

// warn some errors
void cfHelper::error(std::string str) {
    std::cout << str << std::endl;
    exit(-1);
}

// test the source code
void cfHelper::test(std::string str) {
    std::string com = "g++ ";
    std::string fn = str + ".cpp";
    com += fn + " --std=c++11 -O2 -o " + str;
    std::cout << com << std::endl;
    //int ret = system(com.c_str());
    //if (ret) {
    //    error("Error occurred when compile!");
    //}
}

