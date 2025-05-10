#pragma once

#include <string>

/**
 * OpenGL
 * NOTE: GLAD library must go first and before other OpenGL libs
 */
#include <glad/glad.h>

#include <GLFW/glfw3.h>

/**
 * This is a base class for Window object. The main
 * purpose of this class it initialize OpenGL context
 * and create GLFW Window.
 */
class WindowBase {
  private:
    /** Init functions */
    void init(const std::string &name, const unsigned int width, const unsigned int height);
    void initGLFW();
    void initOpenGL();
    void initContext(const std::string &name, const unsigned int width, const unsigned int height);
    void initGLAD();

  protected:
    GLFWwindow *_window;
    unsigned int _width;
    unsigned int _height;

  public:
    WindowBase();
    WindowBase(const std::string &name, const unsigned int width, const unsigned int height);
    ~WindowBase();

    GLFWwindow *getWindow() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;
};