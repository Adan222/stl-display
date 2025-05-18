#pragma once

/** STD */
#include <string>

namespace utils::string {

/**
* Checks if a string ends with a specified suffix.

* @param fullString The full string to evaluate.
* @param ending The expected ending substring.

* @return True if the full string ends with the specified ending, false otherwise.
*/
bool endsWith(const std::string &fullString, const std::string &ending);

} // namespace utils::string