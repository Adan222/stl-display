#include "Entity.hpp"

/** OpenGL classes */
#include "opengl/Texture.hpp"
#include "opengl/VertexBufferObject.hpp"

/** GLM */
#include <glm/gtc/type_ptr.hpp>

/** Lib */
#include "opengl/Vertex.hpp"

namespace stl {

Entity::Entity() : _vao(), _shaderProgram(), _brick_texture(0), _face_texture(1) {}

Entity::~Entity() {}

void Entity::setup() {
    // Create shaders
    Shader fragmentShader(Shader::Type::Fragment, "fragment.frag");
    fragmentShader.checkError();
    Shader vertexShader(Shader::Type::Vertex, "vertex.vert");
    vertexShader.checkError();

    // Programs
    _shaderProgram.attacheShader(vertexShader);
    _shaderProgram.attacheShader(fragmentShader);
    _shaderProgram.linkShaders();

    // VAO
    _vao.bind();

    // VBO
    Vertex vertices[] = { // Back face (red)
                          { { -0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f } },
                          { { 0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 0.0f } },
                          { { 0.5f, 0.5f, -0.5f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f } },
                          { { 0.5f, 0.5f, -0.5f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f } },
                          { { -0.5f, 0.5f, -0.5f }, { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f } },
                          { { -0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f } },

                          // Front face (green)
                          { { -0.5f, -0.5f, 0.5f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f } },
                          { { 0.5f, -0.5f, 0.5f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 0.0f } },
                          { { 0.5f, 0.5f, 0.5f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f } },
                          { { 0.5f, 0.5f, 0.5f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f } },
                          { { -0.5f, 0.5f, 0.5f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 1.0f } },
                          { { -0.5f, -0.5f, 0.5f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f } },

                          // Left face (blue)
                          { { -0.5f, 0.5f, 0.5f }, { 0.0f, 0.0f, 1.0f }, { 1.0f, 0.0f } },
                          { { -0.5f, 0.5f, -0.5f }, { 0.0f, 0.0f, 1.0f }, { 1.0f, 1.0f } },
                          { { -0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f } },
                          { { -0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f } },
                          { { -0.5f, -0.5f, 0.5f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 0.0f } },
                          { { -0.5f, 0.5f, 0.5f }, { 0.0f, 0.0f, 1.0f }, { 1.0f, 0.0f } },

                          // Right face (yellow)
                          { { 0.5f, 0.5f, 0.5f }, { 1.0f, 1.0f, 0.0f }, { 1.0f, 0.0f } },
                          { { 0.5f, 0.5f, -0.5f }, { 1.0f, 1.0f, 0.0f }, { 1.0f, 1.0f } },
                          { { 0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f, 0.0f }, { 0.0f, 1.0f } },
                          { { 0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f, 0.0f }, { 0.0f, 1.0f } },
                          { { 0.5f, -0.5f, 0.5f }, { 1.0f, 1.0f, 0.0f }, { 0.0f, 0.0f } },
                          { { 0.5f, 0.5f, 0.5f }, { 1.0f, 1.0f, 0.0f }, { 1.0f, 0.0f } },

                          // Bottom face (cyan)
                          { { -0.5f, -0.5f, -0.5f }, { 0.0f, 1.0f, 1.0f }, { 0.0f, 1.0f } },
                          { { 0.5f, -0.5f, -0.5f }, { 0.0f, 1.0f, 1.0f }, { 1.0f, 1.0f } },
                          { { 0.5f, -0.5f, 0.5f }, { 0.0f, 1.0f, 1.0f }, { 1.0f, 0.0f } },
                          { { 0.5f, -0.5f, 0.5f }, { 0.0f, 1.0f, 1.0f }, { 1.0f, 0.0f } },
                          { { -0.5f, -0.5f, 0.5f }, { 0.0f, 1.0f, 1.0f }, { 0.0f, 0.0f } },
                          { { -0.5f, -0.5f, -0.5f }, { 0.0f, 1.0f, 1.0f }, { 0.0f, 1.0f } },

                          // Top face (magenta)
                          { { -0.5f, 0.5f, -0.5f }, { 1.0f, 0.0f, 1.0f }, { 0.0f, 1.0f } },
                          { { 0.5f, 0.5f, -0.5f }, { 1.0f, 0.0f, 1.0f }, { 1.0f, 1.0f } },
                          { { 0.5f, 0.5f, 0.5f }, { 1.0f, 0.0f, 1.0f }, { 1.0f, 0.0f } },
                          { { 0.5f, 0.5f, 0.5f }, { 1.0f, 0.0f, 1.0f }, { 1.0f, 0.0f } },
                          { { -0.5f, 0.5f, 0.5f }, { 1.0f, 0.0f, 1.0f }, { 0.0f, 0.0f } },
                          { { -0.5f, 0.5f, -0.5f }, { 1.0f, 0.0f, 1.0f }, { 0.0f, 1.0f } }
    };

    VertexBufferObject vbo;
    vbo.setData(vertices, sizeof(vertices));

    /** Configure attributes */

    // Vertex position
    AttributeConfiguration vertexConfig = { .index = 0,
                                            .size = 3,
                                            .dataType = AttributeConfiguration::Type::FLOAT,
                                            .normalize = false,
                                            .stride = sizeof(Vertex),
                                            .startPointer = 0 };
    _vao.configureAttribute(vertexConfig);

    // Vertex color
    AttributeConfiguration colorConfig = { .index = 1,
                                           .size = 3,
                                           .dataType = AttributeConfiguration::Type::FLOAT,
                                           .normalize = false,
                                           .stride = sizeof(Vertex),
                                           .startPointer = sizeof(VertexPosition) };
    _vao.configureAttribute(colorConfig);

    // Vertex texture
    AttributeConfiguration textureConfig = { .index = 2,
                                             .size = 2,
                                             .dataType = AttributeConfiguration::Type::FLOAT,
                                             .normalize = false,
                                             .stride = sizeof(Vertex),
                                             .startPointer = 6 * sizeof(float) };
    _vao.configureAttribute(textureConfig);

    // Textures
    _brick_texture.loadImage("/woodencontainer.png");
    _face_texture.loadImage("/awesomeface.png");

    // Assign texture units
    _shaderProgram.useProgram();
    _shaderProgram.setUniformInt("Texture0", 0);
    _shaderProgram.setUniformInt("Texture1", 1);
}

void Entity::model(const glm::mat4 &matrix) const {
    _shaderProgram.useProgram();
    _shaderProgram.setUniformMatrix4f("model", glm::value_ptr(matrix));
}

void Entity::view(const glm::mat4 &matrix) const {
    _shaderProgram.useProgram();
    _shaderProgram.setUniformMatrix4f("view", glm::value_ptr(matrix));
}

void Entity::projection(const glm::mat4 &matrix) const {
    _shaderProgram.useProgram();
    _shaderProgram.setUniformMatrix4f("projection", glm::value_ptr(matrix));
}

void Entity::draw() const {
    _shaderProgram.useProgram();
    _vao.bind();
    _brick_texture.bindTexture();
    _face_texture.bindTexture();

    glDrawArrays(GL_TRIANGLES, 0, 36);
}

} // namespace stl