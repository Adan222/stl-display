#pragma once

#include <string>

/**
 * OpenGL
 * NOTE: GLAD library must go first and before other OpenGL libs
 */
#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include "window/WindowDrawHandler.hpp"
#include "window/WindowEventHandler.hpp"

/**
 * Class for handling app window.
 */
class Window : public WindowEventHandler, public WindowDrawHandler {
  public:
    Window(const std::string &name, const unsigned int width, const unsigned int height);
    ~Window();

    bool isOpen() const;
    void close();
};