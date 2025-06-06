#include "Program.hpp"

/** STD */
#include <iostream>

/** Core */
#include "core/Renderer.hpp"

/** Utils */
#include "utils/String.hpp"

/** Private methods */

std::vector<std::string> Program::createArguments(int argc, char *argv[]) {
    std::vector<std::string> args(argc);
    for (int i = 0; i < argc; i++)
        args[i] = std::string(argv[i]);

    return args;
}

void Program::printHelpMessage() const {
    std::cout << "Usage: stlviewer [options] <file.stl>\n"
              << "Options:\n"
              << "  -h, --help              Show this help message\n";
}

/** Constructors */

Program::Program(int argc, char *argv[]) { _arguments = createArguments(argc, argv); }

Program::~Program() {}

/** Public methods */

void Program::run() {
    if (_arguments.size() < 2) {
        std::cerr << "No STL file given\n";
        printHelpMessage();
        return;
    }

    // Settings
    std::string stlFile;

    for (int i = 1; i < _arguments.size(); ++i) {
        const std::string &arg = _arguments[i];

        if (arg == "-h" || arg == "--help") {
            printHelpMessage();
            return;
        }

        else if (utils::string::endsWith(arg, ".stl"))
            stlFile = arg;

        else {
            std::cerr << "Unknown argument: " << arg << "\n";
            printHelpMessage();
            return;
        }
    }

    if (stlFile.empty()) {
        std::cerr << "No STL file provided.\n";
        return;
    }

    constexpr unsigned int width = 800;
    constexpr unsigned int height = 600;
    Renderer renderer(width, height);
    renderer.run(stlFile);
}
