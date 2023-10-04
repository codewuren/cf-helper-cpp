#include "cf-helper.h"

// print help info
void cfHelper::help() {
    std::cout << "Usage: " << std::endl;
    std::cout << "  cf gen [TestName]\tGenerate a solution" << std::endl;
    std::cout << "  cf test [TestName]\tTest a solution" << std::endl;
    std::cout << "  cf user-info\t\tGet user info" << std::endl;
}

// warn some errors
void cfHelper::error(std::string str) {
    std::cout << str << std::endl;
    exit(-1);
}

// compile the source code and run
void cfHelper::test(std::string str) {
    std::string com = "g++ ";
    std::string fn = str + ".cpp";
    com += fn + " --std=c++11 -O2 -o " + str + " && ./" + str;
    std::cout << com << std::endl;
    int ret = system(com.c_str());
    if (ret) {
        error("Error occurred when compile!");
    }
}

// generate template code
void cfHelper::genCode(std::string fn) {
    // read from template file and create a new file, output the contents in template file to the new file.
    std::ifstream ifs;
    std::string temname = "template";
    ifs.open(temname.c_str());
    std::vector<std::string> fc;
    std::string line;
    if (ifs.is_open()) {
        while (std::getline(ifs, line)) {
            fc.push_back(line);
            std::cout << line << std::endl;
        }
    }
    ifs.close();
    std::ofstream ofs;
    std::string filename = fn + ".cpp";
    ofs.open(filename.c_str());
    for (auto v : fc) {
        ofs << v << std::endl;
    }
    ofs.close();
}

void cfHelper::getUserInfo() {
    // TODO
}
