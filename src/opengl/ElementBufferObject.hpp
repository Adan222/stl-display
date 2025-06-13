#pragma once

/** STD */
#include <cstddef>

/** GLAD */
#include <glad/glad.h>

/**
 * Class that represents Element Buffer Object in OpenGL
 */
class ElementBufferObject {
  private:
    GLuint _id;

  public:
    ElementBufferObject();
    ~ElementBufferObject();

    /**
     * Set indices data for Element Buffer Object
     */
    void setData(const void *data, std::size_t size);
};