#include "cf-helper.h"

// print help info
void cfHelper::help() {
    std::cout << "Usage: " << std::endl;
    std::cout << "  cf-helper gen [TestName]\tGenerate a solution" << std::endl;
    std::cout << "  cf-helper test [TestName]\tTest a solution" << std::endl;
    std::cout << "  cf-helper user-info\t\tGet user info" << std::endl;
}

// read a file and return the contents as a vector
void cfHelper::readFile(std::vector<std::string>& vec, std::string filename) {
    std::ifstream ifs;
    ifs.open(filename.c_str());
    std::string line;
    if (ifs.is_open()) {
        while (getline(ifs, line)) vec.push_back(line);
        ifs.close();
    }
    else {
        ifs.close();
        cfHelper::error("readFile() failed: couldn't open file \"" + filename + "\"!", true);
    }
}

void cfHelper::readFile(std::string* str, std::string filename) {
    std::ifstream ifs;
    ifs.open(filename.c_str());
    if (ifs.is_open()) {
        getline(ifs, *str);
        ifs.close();
    }
    else {
        ifs.close();
        cfHelper::error("readFile() failed: couldn't open file \"" + filename + "\"!", true);
    }
}

// write the contents in vec into a file
void cfHelper::writeFile(std::string filename, std::vector<std::string> vec) {
    std::ofstream ofs;
    ofs.open(filename.c_str());
    if (ofs.is_open()) {
        for (auto v : vec) {
            ofs << v << std::endl;
        }
    }
    else cfHelper::error("writeFile failed: couldn't write file \"" + filename + "\"!", true);
    ofs.close();
}

// warn a error and exit if exit_yon is true
void cfHelper::error(std::string str, bool exit_yon) {
    std::cout << str << std::endl;
    if (exit_yon) {
        exit(-1);
    }
}

// compile the source code and run
void cfHelper::test(std::string str) {
    std::string com = "g++ " + str + ".cpp" + " --std=c++11 -O2 -o " + str + " && ./" + str;
    std::cout << com << std::endl;
    int ret = system(com.c_str());
    if (ret) {
        cfHelper::error("Error occurred when compile!", true);
    }
}

// generate template code
void cfHelper::genCode(std::string testname) {
    // read from template file and create a new file, output the contents in template file to the new file.
    int ret = system("mkdir ~/.config/cf-helper");
    if (!ret || ret != 256) cfHelper::error("mkdir failed!", true);

    // get user directory
    ret = system("echo $HOME > user_home.txt");
    if (ret) cfHelper::error("echo $HOME failed!", true);
    std::string user_home = "";
    cfHelper::readFile(&user_home, "user_home.txt");

    // get the full-name of the template file
    std::string template_path = user_home + "/.config/cf-helper/template";
    std::cout << "template file located in " << template_path << std::endl;

    // delete user_home.txt
    system("rm user_home.txt");

    // get the content of the template file
    std::vector<std::string> file_content;
    cfHelper::readFile(file_content, template_path);

    // write the content of the template file into the target file
    std::string filename = testname + ".cpp";
    writeFile(filename, file_content);
}
