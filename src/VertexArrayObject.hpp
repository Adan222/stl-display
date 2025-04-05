#pragma once

#include <cstddef>

#include <glad/glad.h>

/**
 * Attribute configuration
 */
struct AttributeConfiguration {
    enum Type {
        FLOAT,
        // ...
    };

    unsigned int index;
    int size;
    AttributeConfiguration::Type dataType;
    bool normalize;
    size_t stride;
    int startPointer;

    static unsigned int getGlType(const AttributeConfiguration::Type t);
};

/**
 * Class that represents Vertex Array Object
 */
class VertexArrayObject {
  private:
    GLuint _id;

  public:
    VertexArrayObject();
    ~VertexArrayObject();

    /**
     * Bind this VAO
     */
    void bind() const;

    /**
     * Unbind any VAO
     */
    static void unbind();

    void configureAttribute(const AttributeConfiguration &config);
};