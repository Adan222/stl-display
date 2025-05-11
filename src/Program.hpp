#pragma once

/**
 * OpenGL
 * NOTE: GLAD library must go first and before other OpenGL libs
 */
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <glm/ext/matrix_float4x4.hpp>

/** Lib */
#include "EventHandler.hpp"
#include "Window.hpp"

class Program {
  private:
    Window window;
    EventHandler _eventHandler;

    /** Variables */
    glm::mat4 _modelMatrix;
    glm::mat4 _rotationMatrix;

  public:
    Program(unsigned int width, unsigned int height);
    ~Program();

    void run();

    Window *getWindow();

    /** Functionality */
    void handleDrag(int dx, int dy);
};