#include "Window.hpp"

#include "window/WindowBase.hpp"

/** Constructors */

Window::Window(const std::string &name, const unsigned int width, const unsigned int height)
    : WindowBase(name, width, height) {}

Window::~Window() {}