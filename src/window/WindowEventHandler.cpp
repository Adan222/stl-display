#include "WindowEventHandler.hpp"

#include <GLFW/glfw3.h>

/** Callback methods */

void WindowEventHandler::framebuffer_size_callback(GLFWwindow *window,
                                                   int new_width,
                                                   int new_height) {
    glViewport(0, 0, new_width, new_height);
}

void WindowEventHandler::cursor_position_callback(GLFWwindow *window, double x, double y) {
    Event event(Event::Type::MouseMoved);
    event.mouseMove.x = x;
    event.mouseMove.y = y;

    _eventQueue.push(event);
}

void WindowEventHandler::mouse_button_callback(GLFWwindow *window,
                                               int button,
                                               int action,
                                               int mods) {
    // Check type
    Event::Type type = Event::Type::None;
    switch (action) {
    case GLFW_PRESS:
        type = Event::Type::MouseButtonPressed;
        break;
    case GLFW_RELEASE:
        type = Event::Type::MouseButtonReleased;
        break;

    default:
        break;
    }

    Event event(type);

    // Check button
    switch (button) {
    case GLFW_MOUSE_BUTTON_LEFT:
        event.mouseButton.button = Event::MouseButton::Left;
        break;

    case GLFW_MOUSE_BUTTON_RIGHT:
        event.mouseButton.button = Event::MouseButton::Right;
        break;
    }

    // Get coordinates
    glfwGetCursorPos(window, &event.mouseButton.x, &event.mouseButton.y);

    _eventQueue.push(event);
}

void WindowEventHandler::key_callback(
    GLFWwindow *window, int key, int scancode, int action, int mods) {
    // Check type
    Event::Type type = Event::Type::None;
    switch (action) {
    case GLFW_PRESS:
        type = Event::Type::KeyPressed;
        break;
    case GLFW_RELEASE:
        type = Event::Type::KeyReleased;
        break;

    default:
        break;
    }

    Event event(type);
    event.keyEvent.key = Event::Key(key);

    _eventQueue.push(event);
}

/** Constructors */

WindowEventHandler::WindowEventHandler() {
    /** Set all callbacks */
    glfwSetFramebufferSizeCallback(_window, WindowEventHandler::framebuffer_size_callback);
    glfwSetCursorPosCallback(_window, WindowEventHandler::cursor_position_callback);
    glfwSetMouseButtonCallback(_window, WindowEventHandler::mouse_button_callback);
    glfwSetKeyCallback(_window, WindowEventHandler::key_callback);
}

WindowEventHandler::~WindowEventHandler() {}

/** Public methods */

Event WindowEventHandler::poolEvents() {
    if (_eventQueue.empty())
        return Event(Event::Type::None);

    Event event = _eventQueue.front();
    _eventQueue.pop();

    return event;
}

/** Event queue */
std::queue<Event> WindowEventHandler::_eventQueue;