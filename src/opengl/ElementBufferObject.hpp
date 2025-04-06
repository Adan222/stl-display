#pragma once

#include <cstddef>

#include <glad/glad.h>

class ElementBufferObject {
  private:
    GLuint _id;

  public:
    ElementBufferObject();
    ~ElementBufferObject();

    void setData(const void *data, std::size_t size);
};