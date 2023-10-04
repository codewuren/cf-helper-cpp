#include "cf-helper.h"


int main(int argc, char** argv) {
    cfHelper cfhelper;  // create a cfHelper object

    // read the arguments
    if (argc == 1) {
        cfhelper.help();
        exit(-1);
    }
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
            cfhelper.help();
        }
        else if (!strcmp(argv[i], "test")) {
            if(argv[i + 1][0] >= 'A') {
                cfhelper.test(argv[i + 1]);
            }
            else {
                cfhelper.error("Wrong Input!");
            }
        }
    }

    return 0;
}
