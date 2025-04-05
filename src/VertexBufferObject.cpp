#include "VertexBufferObject.hpp"

#include <cstddef>

VertexBufferObject::VertexBufferObject() { glGenBuffers(1, &this->_id); }

VertexBufferObject::~VertexBufferObject() {}

void VertexBufferObject::setData(const void *data, std::size_t size) {
    glBindBuffer(GL_ARRAY_BUFFER, this->_id);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}