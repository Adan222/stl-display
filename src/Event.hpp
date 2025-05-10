#pragma once

class Event {
  public:
    /** Event enums  */
    enum class Type {
        None,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        KeyPressed,
        KeyReleased
    };
    enum class MouseButton { Left = 0, Right = 1, Middle = 2 };
    enum class Key {
        Space = 32,
        Apostrophe = 39,
        Comma = 44,
        Minus = 45,
        Period = 46,
        Slash = 47,
        D0 = 48,
        D1 = 49,
        D2 = 50,
        D3 = 51,
        D4 = 52,
        D5 = 53,
        D6 = 54,
        D7 = 55,
        D8 = 56,
        D9 = 57,
        Semicolon = 59,
        Equal = 61,
        A = 65,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,
        LeftBracket = 91,
        Backslash = 92,
        RightBracket = 93,
        GraveAccent = 96,
        World1 = 161,
        World2 = 162,

        Escape = 256,
        Enter,
        Tab,
        Backspace,
        Insert,
        Delete,
        Right,
        Left,
        Down,
        Up,
        PageUp,
        PageDown,
        Home,
        End,
        CapsLock = 280,
        ScrollLock,
        NumLock,
        PrintScreen,
        Pause,

        F1 = 290,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
        F13,
        F14,
        F15,
        F16,
        F17,
        F18,
        F19,
        F20,
        F21,
        F22,
        F23,
        F24,
        F25,

        KP_0 = 320,
        KP_1,
        KP_2,
        KP_3,
        KP_4,
        KP_5,
        KP_6,
        KP_7,
        KP_8,
        KP_9,
        KP_Decimal,
        KP_Divide,
        KP_Multiply,
        KP_Subtract,
        KP_Add,
        KP_Enter,
        KP_Equal,

        LeftShift = 340,
        LeftControl,
        LeftAlt,
        LeftSuper,
        RightShift,
        RightControl,
        RightAlt,
        RightSuper,
        Menu,

        Last = Menu
    };

    /** Event structures */

    struct MouseMoveEvent {
        double x, y;
    };

    struct MouseButtonEvent {
        MouseButton button;
        double x, y;
    };

    struct KeyEvent {
        Key key;
    };

    /** Event variables */

    Type type;
    union {
        MouseMoveEvent mouseMove;
        MouseButtonEvent mouseButton;
        KeyEvent keyEvent;
    };

    /** Event methods */

    Event(Type type);
    ~Event();

    explicit operator bool() const;
};
