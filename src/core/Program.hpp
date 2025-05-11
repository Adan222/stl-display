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
#include "window/Window.hpp"

class Program {
  private:
    Window window;
    EventHandler _eventHandler;

    /** Variables */
    glm::mat4 _modelMatrix;

    /** Private methods */
    glm::vec3 mapToArcball(int x, int y);

  public:
    Program(unsigned int width, unsigned int height);
    ~Program();

    void run();

    Window *getWindow();

    /** Functionality */
    void handleDrag(int startX, int startY, int endX, int endY);
};