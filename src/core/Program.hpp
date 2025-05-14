#pragma once

/** STD */
#include <string>
#include <vector>

class Program {
    /** Private methods */
    std::vector<std::string> createArguments(int argc, char *argv[]);
    void printHelpMessage() const;
    bool endsWith(const std::string &fullString, const std::string &ending);

    /** Variables */
    std::vector<std::string> _arguments;

  public:
    Program(int argc, char *argv[]);
    ~Program();

    void run();
};