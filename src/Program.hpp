#pragma once

/**
 * OpenGL
 * NOTE: GLAD library must go first and before other OpenGL libs
 */
#include <glad/glad.h>

#include <GLFW/glfw3.h>

class Program {
  private:
    GLFWwindow *_window;
    unsigned int _window_width;
    unsigned int _widnow_height;

    void initOpenGL();

    void processInput();

  public:
    Program(unsigned int width, unsigned int height);
    ~Program();

    void run();
};