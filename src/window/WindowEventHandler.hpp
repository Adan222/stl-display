#pragma once

#include <queue>

#include "Event.hpp"

#include "window/WindowBase.hpp"

class WindowEventHandler : public virtual WindowBase {
  private:
    /** Callback methods */
    static void framebuffer_size_callback(GLFWwindow *window, int new_width, int new_height);

    /** Queue  */
    std::queue<Event> _eventQueue;

  public:
    WindowEventHandler();
    ~WindowEventHandler();

    bool isOpen() const;

    void poolEvents();
};