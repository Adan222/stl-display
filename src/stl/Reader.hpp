#pragma once

#include "stl/Mesh.hpp"
#include <fstream>

namespace stl {

/**
 * Interface for reading .stl files
 */
class Reader {
  private:
    std::fstream _fstream;

  public:
    Reader(std::fstream &&fstream);
    ~Reader();

    virtual stl::Mesh read() const = 0;
};

} // namespace stl