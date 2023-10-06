#ifndef CF_HELPER_H
#define CF_HELPER_H

// Include some libraries
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>

namespace cwr {
    namespace tools {
        class cfHelper {
        public:
            cfHelper(){};
            ~cfHelper(){};

        public:
            // some functions
            void help();
            void test(std::string str);
            void error(std::string str, bool exit_yon);
            void genCode(std::string testname);
            void readFile(std::vector<std::string> &vec, std::string filename);
            void readFile(std::string *str, std::string filename);
            void writeFile(std::string filename, std::vector<std::string> vec);

        private:
        };
    }
}
#endif
