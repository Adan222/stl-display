#pragma once

class Event {
  public:
    enum class Type { None, MouseButtonPressed, MouseButtonReleased, MouseMoved };

    enum class MouseButton { Left = 0, Right = 1, Middle = 2 };

    struct MouseMoveEvent {
        double x, y;
    };

    struct MouseButtonEvent {
        MouseButton button;
        double x, y;
    };

    Type type;
    union {
        MouseMoveEvent mouseMove;
        MouseButtonEvent mouseButton;
    };

    Event(Type type);
    ~Event();

    explicit operator bool() const;
};
