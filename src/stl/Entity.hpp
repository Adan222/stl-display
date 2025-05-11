#pragma once

/** OpenGL classes */
#include "opengl/ShaderProgram.hpp"
#include "opengl/Texture.hpp"
#include "opengl/VertexArrayObject.hpp"

/** GLM */
#include <glm/glm.hpp>

/** Lib */
#include "window/Drawable.hpp"

namespace stl {

class Entity : public Drawable {
  private:
    VertexArrayObject _vao;
    ShaderProgram _shaderProgram;

    // Textures
    Texture _brick_texture;
    Texture _face_texture;

  public:
    Entity();
    ~Entity();

    void setup();

    void model(const glm::mat4 &matrix) const;
    void view(const glm::mat4 &matrix) const;
    void projection(const glm::mat4 &matrix) const;

    void draw() const;
};

} // namespace stl