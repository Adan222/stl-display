#include "VertexArrayObject.hpp"

#include <stdexcept>

unsigned int AttributeConfiguration::getGlType(const AttributeConfiguration::Type t) {
    switch (t) {
    case AttributeConfiguration::Type::FLOAT:
        return GL_FLOAT;
    default:
        throw std::runtime_error("Unknown AttributeConfiguration::Type");
    }
}

VertexArrayObject::VertexArrayObject() { glGenVertexArrays(1, &this->_id); }

VertexArrayObject::~VertexArrayObject() {}

void VertexArrayObject::bind() const { glBindVertexArray(this->_id); }

void VertexArrayObject::unbind() { glBindVertexArray(0); }

void VertexArrayObject::configureAttribute(const AttributeConfiguration &config) {
    const GLuint index = config.index;
    const GLint size = config.size;
    const GLenum type = AttributeConfiguration::getGlType(config.dataType);
    const GLboolean normalized = config.normalize;
    const GLsizei stride = config.stride;
    const void *pointer = (void *)(uintptr_t)config.startPointer;

    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(index);
}