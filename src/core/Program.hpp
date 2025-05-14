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

    /**
     * Checks if a string ends with a specified suffix.

     * @param fullString The full string to evaluate.
     * @param ending The expected ending substring.

     * @return True if the full string ends with the specified ending, false otherwise.
     */
    bool endsWith(const std::string &fullString, const std::string &ending);

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
