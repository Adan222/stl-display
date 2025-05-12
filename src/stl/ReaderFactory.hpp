#pragma once

#include "stl/Reader.hpp"
#include <memory>
#include <string>

namespace stl {

class ReaderFactory {
  private:
    const std::string _path;

  public:
    ReaderFactory(const std::string &path);
    ~ReaderFactory();

    std::unique_ptr<Reader> getReader() const;
};

} // namespace stl