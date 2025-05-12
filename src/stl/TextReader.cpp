#include "TextReader.hpp"

#include <iostream>

#include "stl/Mesh.hpp"
#include "stl/Reader.hpp"

/** Constructors */

stl::TextReader::TextReader(std::fstream &&fstream) : stl::Reader(std::move(fstream)) {}

stl::TextReader::~TextReader() {}

/** Public methods */

stl::Mesh stl::TextReader::read() const {
    std::cout << "TextReader\n";
    return Mesh(std::vector<Triangle>());
}