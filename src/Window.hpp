#pragma once

#include <string>

/**
 * OpenGL
 * NOTE: GLAD library must go first and before other OpenGL libs
 */
#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include "Color.hpp"
#include "Drawable.hpp"

/**
 * Class for handling app window.
 */
class Window {
  private:
    GLFWwindow *_window;

    unsigned int _width;
    unsigned int _height;

    /** Init functions */
    void init(const std::string &name, const unsigned int width, const unsigned int height);
    void initGLFW();
    void initOpenGL();
    void initContext(const std::string &name, const unsigned int width, const unsigned int height);
    void initGLAD();

    /** GLFW callbacks */
    static void framebuffer_size_callback(GLFWwindow *window, int new_width, int new_height);

  public:
    Window(const std::string &name, const unsigned int width, const unsigned int height);
    ~Window();

    GLFWwindow *getWindow() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    bool isOpen() const;

    void clear(const Color &color);
    void draw(const Drawable &object);
    void display();
};