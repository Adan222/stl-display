#include <exception>
#include <iostream>

#include "core/Program.hpp"

int main() {
    try {
        constexpr unsigned int width = 800;
        constexpr unsigned int height = 600;

        Program program(width, height);
        program.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }
}