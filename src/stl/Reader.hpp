#pragma once

#include "stl/Mesh.hpp"
#include <fstream>

namespace stl {

/**
 * Interface for reading .stl files
 */
class Reader {
  protected:
    mutable std::ifstream _fstream;

  public:
    Reader(std::ifstream &&fstream);
    ~Reader();

    virtual stl::Mesh read() const = 0;
};

} // namespace stl