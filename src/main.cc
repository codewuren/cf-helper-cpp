#include "cf-helper.h"


int main(int argc, char** argv) {
    cfHelper cf;  // create a cfHelper object

    // read the arguments
    if (argc == 1) {
        cf.help();
        exit(-1);
    }
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
            cf.help();
        }
        else if (!strcmp(argv[i], "-g") || !strcmp(argv[i], "gen")) {
            cf.genCode(argv[i + 1]);
        }
        else if (!strcmp(argv[i], "test")) {
            if(argv[i + 1][0] >= 'A') {
                cf.test(argv[i + 1]);
            }
            else {
                cf.error("Wrong Input!", true);
            }
        }
    }

    return 0;
}
