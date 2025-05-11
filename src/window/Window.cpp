#include "Window.hpp"

#include "window/WindowBase.hpp"

/** Constructors */

Window::Window(const std::string &name, const unsigned int width, const unsigned int height)
    : WindowBase(name, width, height) {}

Window::~Window() {}

/** Public methods */

bool Window::isOpen() const { return !glfwWindowShouldClose(_window); }

void Window::close() { glfwSetWindowShouldClose(_window, GLFW_TRUE); }
