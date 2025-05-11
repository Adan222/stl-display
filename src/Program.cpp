#include "Program.hpp"

#include <cmath>

/** GLM */
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/quaternion_trigonometric.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/** Lib */
#include "Window.hpp"

/** STL */
#include "stl/Entity.hpp"

/** Constructors */

Program::Program(unsigned int width, unsigned int height)
    : window("OpenGL", width, height), _eventHandler(this), _rotationMatrix(glm::mat4(1.0f)),
      _modelMatrix(1.0f) {}

Program::~Program() {}

/** Public methods */

void Program::run() {
    stl::Entity entity;
    entity.setup();

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    entity.view(view);

    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    entity.projection(projection);

    while (window.isOpen()) {
        window.clear({ 0.2f, 0.3f, 0.3f, 1.0f });

        _eventHandler.handleEvents();

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model,
                            (float)glfwGetTime() * glm::radians(50.0f),
                            glm::vec3(0.5f, 1.0f, 0.0f));
        entity.model(model);

        window.draw(entity);

        window.display();
    }
}

Window *Program::getWindow() { return &window; }

void Program::handleDrag(int dx, int dy) {}