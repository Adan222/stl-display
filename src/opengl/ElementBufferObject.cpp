#include "ElementBufferObject.hpp"

#include <cstddef>

ElementBufferObject::ElementBufferObject() { glGenBuffers(1, &this->_id); }

ElementBufferObject::~ElementBufferObject() {}

void ElementBufferObject::setData(const void *data, std::size_t size) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}