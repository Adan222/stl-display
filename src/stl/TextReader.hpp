#pragma once

#include "stl/Reader.hpp"

namespace stl {

class TextReader : public stl::Reader {
  public:
    TextReader(std::fstream &&fstream);
    ~TextReader();

    stl::Mesh read() const;
};

} // namespace stl