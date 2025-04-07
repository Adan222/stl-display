#include "Window.hpp"

#include <stdexcept>
#include <string>

void Window::init(const std::string &name, const unsigned int width, const unsigned int height) {
    initGLFW();
    initOpenGL();
    initContext(name, width, height);
    initGLAD();

    /** ===== GLFW Callbacks ===== */
    glfwSetFramebufferSizeCallback(_window, Window::framebuffer_size_callback);

    /** ===== OpenGL extensions ===== */
    glEnable(GL_DEPTH_TEST);
}

void Window::initGLFW() {
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW!");
}

void Window::initOpenGL() {
    // Set OpenGL version to 3.3 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Window::initContext(const std::string &name,
                         const unsigned int width,
                         const unsigned int height) {
    // Create a window
    _window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    if (!_window)
        throw std::runtime_error("Failed to create GLFW window!");
    glfwMakeContextCurrent(_window);
}

void Window::initGLAD() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize GLAD!");
}

void Window::framebuffer_size_callback(GLFWwindow *window, int new_width, int new_height) {
    glViewport(0, 0, new_width, new_height);
}

Window::Window(const std::string &name, const unsigned int width, const unsigned int height)
    : _width(width), _height(height) {
    init(name, width, height);

    // Create basic OpenGL viewport
    glViewport(0, 0, width, height);
}

Window::~Window() {
    glfwDestroyWindow(_window);
    glfwTerminate();
}

GLFWwindow *Window::getWindow() const { return _window; }

unsigned int Window::getWidth() const { return _width; }

unsigned int Window::getHeight() const { return _height; }

bool Window::isOpen() const { return !glfwWindowShouldClose(_window); }

void Window::clear(const Color &color) {
    glClearColor(color.r, color.g, color.b, color.a);

    // Clear color and z-buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::draw(const Drawable &object) { object.draw(); }

void Window::display() {
    glfwSwapBuffers(_window);
    glfwPollEvents();
}
