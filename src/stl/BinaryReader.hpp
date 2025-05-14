#pragma once

/** STL */
#include "stl/Reader.hpp"

namespace stl {

class BinaryReader : public stl::Reader {
  private:
    /** Private structures */
    struct Point {
        float x, y, z;
    };

#pragma pack(push, 1)
    struct StlBinaryTriangle {
        Point normal;
        Point vertices[3];
        uint16_t attributeByteCount;
    };
#pragma pack(pop)

  public:
    BinaryReader(std::ifstream &&ifstream);
    ~BinaryReader();

    stl::Mesh read() const;
};

} // namespace stl