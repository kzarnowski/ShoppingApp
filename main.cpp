#include <iostream>
#include "App.h"
#include <fstream>

int main(int argc, char** argv) {
    std::ifstream input;
    if (argc > 1) {
        input.open(argv[1]);
        std::cin.rdbuf(input.rdbuf());
    }

    App myApp;
    while(myApp.isRunning()) {
        myApp.display();
    }
    std::cout << "Closing app";
    return 0;
}
