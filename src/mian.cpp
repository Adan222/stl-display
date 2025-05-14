#include <exception>
#include <iostream>

/** Core */
#include "core/Program.hpp"

int main(int argc, char *argv[]) {
    try {
        Program program(argc, argv);
        program.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }
}