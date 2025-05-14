#include "Reader.hpp"

stl::Reader::Reader(std::ifstream &&ifstream) : _fstream(std::move(ifstream)) {}

stl::Reader::~Reader() { _fstream.close(); }