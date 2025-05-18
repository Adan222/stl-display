#include "utils/String.hpp"

bool utils::string::endsWith(const std::string &fullString, const std::string &ending) {
    if (ending.size() > fullString.size())
        return false;

    return fullString.compare(fullString.size() - ending.size(), ending.size(), ending) == 0;
}
