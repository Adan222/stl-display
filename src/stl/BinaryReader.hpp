#pragma once

#include "stl/Reader.hpp"

namespace stl {

class BinaryReader : public stl::Reader {
  public:
    BinaryReader(std::fstream &&fstream);
    ~BinaryReader();

    stl::Mesh read() const;
};

} // namespace stl