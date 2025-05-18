#pragma once

/** STD */
#include <string>
#include <vector>

/**
 * Entry point class responsible for parsing command-line arguments,
 * handling help messages, and initiating the rendering process.
 */
class Program {
    /** Private methods */

    /**
     * Converts raw command-line arguments into a vector of strings.

     * @param argc Argument count.
     * @param argv Argument values.

     * @return A vector containing the string representations of the arguments.
     */
    std::vector<std::string> createArguments(int argc, char *argv[]);

    /**
     * Prints the usage/help message to the standard output.
     */
    void printHelpMessage() const;

    /** Variables */
    std::vector<std::string> _arguments;

  public:
    /**
     * Constructs the Program instance by parsing input arguments.

     * @param argc Argument count.
     * @param argv Argument values.
     */
    Program(int argc, char *argv[]);
    ~Program();

    /**
     * Entry point for program execution.
     * Parses options and delegates rendering of the STL file.
     */
    void run();
};
