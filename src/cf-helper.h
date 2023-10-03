#ifndef CF_HELPER_H
#define CF_HELPER_H

// Include some libraries
#include <string>
#include <cstring>
#include <iostream>

class cfHelper {
public:
    cfHelper() {};
    ~cfHelper() {};
public:
    void help();
    void test(std::string str);
    void error(std::string str);
private:
};

#endif
