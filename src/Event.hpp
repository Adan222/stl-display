#pragma once

#pragma once

class Event {
  private:
    enum class Type { MouseButtonPressed, MouseButtonReleased, MouseMoved };

    enum class MouseButton { Left = 0, Right = 1, Middle = 2 };

    enum class ButtonAction { Press, Release };

    struct MouseMoveEvent {
        double x, y;
    };

    struct MouseButtonEvent {
        MouseButton button;
        ButtonAction action;
        double x, y;
    };

  public:
    union {
        MouseMoveEvent mouseMove;
        MouseButtonEvent mouseButton;
    };

    Event();
    ~Event();
};
