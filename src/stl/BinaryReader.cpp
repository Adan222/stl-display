#include "BinaryReader.hpp"

#include <iostream>

#include "stl/Mesh.hpp"
#include "stl/Reader.hpp"

/** Constructors */

stl::BinaryReader::BinaryReader(std::fstream &&fstream) : stl::Reader(std::move(fstream)) {}

stl::BinaryReader::~BinaryReader() {}

/** Public methods */

stl::Mesh stl::BinaryReader::read() const {
    std::cout << "BinaryReader\n";
    return Mesh(std::vector<Triangle>());
}
