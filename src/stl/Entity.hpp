#pragma once

/** GLM */
#include <glm/glm.hpp>

/** LIB OpenGL */
#include "opengl/ShaderProgram.hpp"
#include "opengl/VertexArrayObject.hpp"

#include "window/Drawable.hpp"

/** Lib STL */
#include "stl/Mesh.hpp"

namespace stl {

class Entity : public Drawable {
  private:
    const Mesh mesh;

    VertexArrayObject _vao;
    ShaderProgram _shaderProgram;

  public:
    Entity(const Mesh &mesh);
    ~Entity();

    void setup();

    /** Matrix setters */
    void setModelMatrix(const glm::mat4 &matrix) const;
    void setViewMatrix(const glm::mat4 &matrix) const;
    void setProjectionMatrix(const glm::mat4 &matrix) const;

    void draw() const;
};

} // namespace stl