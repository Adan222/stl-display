#pragma once

/** STD lib */
#include <queue>

/** Lib */
#include "Event.hpp"
#include "window/WindowBase.hpp"

class WindowEventHandler : public virtual WindowBase {
  private:
    /** Callback methods */
    static void framebuffer_size_callback(GLFWwindow *window, int new_width, int new_height);
    static void cursor_position_callback(GLFWwindow *window, double x, double y);
    static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    /** Queue  */
    static std::queue<Event> _eventQueue;

  public:
    WindowEventHandler();
    ~WindowEventHandler();

    Event poolEvents();
};