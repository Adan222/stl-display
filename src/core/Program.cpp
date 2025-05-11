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
#include "window/Window.hpp"

/** STL */
#include "stl/Entity.hpp"

/** Private methods */

glm::vec3 Program::mapToArcball(int x, int y) {
    int width = window.getWidth();
    int height = window.getHeight();

    // Normalize vectors
    float nx = (2.0f * x - width) / width;
    float ny = (height - 2.0f * y) / height;

    glm::vec3 v(nx, ny, 0.0f);
    float length2 = nx * nx + ny * ny;

    if (length2 <= 1.0f)
        v.z = sqrt(1.0f - length2);
    else
        v = glm::normalize(v);

    return v;
}

/** Constructors */

Program::Program(unsigned int width, unsigned int height)
    : window("OpenGL", width, height), _eventHandler(this), _modelMatrix(1.0f) {}

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

        entity.model(_modelMatrix);

        window.draw(entity);

        window.display();
    }
}

Window *Program::getWindow() { return &window; }

void Program::handleDrag(int startX, int startY, int endX, int endY) {
    glm::vec3 va = mapToArcball(startX, startY);
    glm::vec3 vb = mapToArcball(endX, endY);

    float angle = acos(glm::clamp(glm::dot(va, vb), -1.0f, 1.0f));
    glm::vec3 axis = glm::cross(va, vb);

    if (glm::length(axis) > 0.0001f) {
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, glm::normalize(axis));
        _modelMatrix = rotationMatrix * _modelMatrix;
    }
}