#include "WindowBase.hpp"

#include <stdexcept>

/** Private methods */

void WindowBase::init(const std::string &name,
                      const unsigned int width,
                      const unsigned int height) {
    initGLFW();
    initOpenGL();
    initContext(name, width, height);
    initGLAD();

    /** ===== OpenGL extensions ===== */
    glEnable(GL_DEPTH_TEST);
}

void WindowBase::initGLFW() {
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW!");
}

void WindowBase::initOpenGL() {
    // Set OpenGL version to 3.3 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void WindowBase::initContext(const std::string &name,
                             const unsigned int width,
                             const unsigned int height) {
    // Create a window
    _window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    if (!_window)
        throw std::runtime_error("Failed to create GLFW window!");
    glfwMakeContextCurrent(_window);
}

void WindowBase::initGLAD() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize GLAD!");
}

/** Constructors */

WindowBase::WindowBase() {}

WindowBase::WindowBase(const std::string &name, const unsigned int width, const unsigned int height)
    : _width(width), _height(height) {
    init(name, width, height);

    // Create basic OpenGL viewport
    glViewport(0, 0, width, height);
}

WindowBase::~WindowBase() {
    glfwDestroyWindow(_window);
    glfwTerminate();
}

/** Public methods */

GLFWwindow *WindowBase::getWindow() const { return _window; }

unsigned int WindowBase::getWidth() const { return _width; }

unsigned int WindowBase::getHeight() const { return _height; }
