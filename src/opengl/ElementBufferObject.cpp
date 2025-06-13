#include "ElementBufferObject.hpp"

/** Constructors */

ElementBufferObject::ElementBufferObject() { glGenBuffers(1, &_id); }

ElementBufferObject::~ElementBufferObject() {}

/** Public methods */

void ElementBufferObject::setData(const void *data, std::size_t size) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}