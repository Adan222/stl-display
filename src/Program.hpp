#pragma once

/**
 * OpenGL
 * NOTE: GLAD library must go first and before other OpenGL libs
 */
#include <glad/glad.h>

#include <GLFW/glfw3.h>

/** Lib */
#include "Window.hpp"

class Program {
  private:
    Window window;

    void processInput();

  public:
    Program(unsigned int width, unsigned int height);
    ~Program();

    void run();
};