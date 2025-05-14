#pragma once

/**
 * OpenGL
 * NOTE: GLAD library must go first and before other OpenGL libs
 */
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <glm/ext/matrix_float4x4.hpp>

/** Lib */
#include "core/EventHandler.hpp"
#include "window/Window.hpp"

/** Lib STL */
#include "stl/Mesh.hpp"

class Renderer {
  private:
    Window window;
    EventHandler _eventHandler;

    /** Variables */
    glm::mat4 _modelMatrix;

    /** Private methods */
    glm::vec3 mapToArcball(int x, int y);
    void centerModel(const stl::Mesh &mesh);

  public:
    Renderer(unsigned int width, unsigned int height);
    ~Renderer();

    void run(const std::string &stlFile);

    Window *getWindow();

    /** Functionality */
    void handleDrag(int startX, int startY, int endX, int endY);
};