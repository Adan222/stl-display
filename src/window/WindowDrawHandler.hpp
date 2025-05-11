#pragma once

#include "Drawable.hpp"

#include "opengl/Color.hpp"
#include "window/WindowBase.hpp"

class WindowDrawHandler : public virtual WindowBase {
  public:
    WindowDrawHandler();
    ~WindowDrawHandler();

    void clear(const Color &color);
    void draw(const Drawable &object);
    void display();
};