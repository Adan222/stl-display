#include "Program.hpp"

#include <cmath>

/** GLM */
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/** Lib */
#include "Window.hpp"

/** STL */
#include "stl/Entity.hpp"

Program::Program(unsigned int width, unsigned int height) : window("OpenGL", width, height) {}

Program::~Program() {}

void Program::processInput() {
    auto win = window.getWindow();
    if (glfwGetKey(win, GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(win, GLFW_TRUE);

    if (glfwGetKey(win, GLFW_KEY_0))
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    if (glfwGetKey(win, GLFW_KEY_1))
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

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

        processInput();

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model,
                            (float)glfwGetTime() * glm::radians(50.0f),
                            glm::vec3(0.5f, 1.0f, 0.0f));
        entity.model(model);

        window.draw(entity);

        window.display();
    }
}