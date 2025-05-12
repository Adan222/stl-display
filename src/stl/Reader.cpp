#include "Reader.hpp"

stl::Reader::Reader(std::fstream &&fstream) : _fstream(std::move(fstream)) {}

stl::Reader::~Reader() { _fstream.close(); }