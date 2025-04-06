#pragma once

#include <cstddef>

#include <glad/glad.h>

class VertexBufferObject {
  private:
    GLuint _id;

  public:
    VertexBufferObject();
    ~VertexBufferObject();

    void setData(const void *data, std::size_t size);
};