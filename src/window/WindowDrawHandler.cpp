#include "WindowDrawHandler.hpp"

#include <GLFW/glfw3.h>

/** Constructors */

WindowDrawHandler::WindowDrawHandler() {}
WindowDrawHandler::~WindowDrawHandler() {}

/** Public methods */

void WindowDrawHandler::clear(const Color &color) {
    glClearColor(color.r, color.g, color.b, color.a);

    // Clear color and z-buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void WindowDrawHandler::draw(const Drawable &object) { object.draw(); }

void WindowDrawHandler::display() {
    glfwSwapBuffers(_window);
    glfwPollEvents();
}
