#include "WindowEventHandler.hpp"
#include <iostream>

/** Private methods */

void WindowEventHandler::framebuffer_size_callback(GLFWwindow *window,
                                                   int new_width,
                                                   int new_height) {
    glViewport(0, 0, new_width, new_height);
}

/** Constructors */

WindowEventHandler::WindowEventHandler() {
    /** Set all callbacks */
    glfwSetFramebufferSizeCallback(_window, WindowEventHandler::framebuffer_size_callback);
}

WindowEventHandler::~WindowEventHandler() {}

bool WindowEventHandler::isOpen() const { return !glfwWindowShouldClose(_window); }
