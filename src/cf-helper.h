#ifndef CF_HELPER_H
#define CF_HELPER_H

// Include some libraries
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>

class cfHelper {
public:
    cfHelper() {};
    ~cfHelper() {};
public:
    // some functions
    void help();
    void test(std::string str);
    void error(std::string str);
    void genCode(std::string fn);
    void getUserInfo();
private:
};

#endif
