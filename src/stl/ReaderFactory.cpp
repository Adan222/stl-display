#include "ReaderFactory.hpp"

#include <cstring>
#include <iostream>
#include <memory>
#include <stdexcept>

#include "stl/BinaryReader.hpp"
#include "stl/TextReader.hpp"

stl::ReaderFactory::ReaderFactory(const std::string &path) : _path(path) {}

stl::ReaderFactory::~ReaderFactory() {}

std::unique_ptr<stl::Reader> stl::ReaderFactory::getReader() const {
    std::fstream fileStream(_path, std::ios::in | std::ios::binary);

    if (!fileStream)
        throw std::runtime_error("Can't read " + _path);

    // Read file to determine type
    char header[5];
    fileStream.read(header, 5);

    // Clear before moving opened file to Reader
    fileStream.clear();
    fileStream.seekg(0, std::ios::beg);
    fileStream.seekp(0, std::ios::beg);

    // If it starts with "solid" then it is text file
    if (std::strncmp(header, "solid", 5) == 0)
        return std::make_unique<TextReader>(std::move(fileStream));
    else
        return std::make_unique<BinaryReader>(std::move(fileStream));
}