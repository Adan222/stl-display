#include "EventHandler.hpp"

#include <iostream>

#include "Event.hpp"
#include "Program.hpp"
#include "Window.hpp"

/** Private methods */

void EventHandler::handleMouseMovement(const Event &event) {
    if (isDragging) {
        auto x = event.mouseMove.x;
        auto y = event.mouseMove.y;

        int dx = x - oldX;
        int dy = y - oldY;

        oldX = x;
        oldY = y;

        _program->handleDrag(dx, dy);
    }
}

void EventHandler::handleMousePress(const Event &event) {
    if (event.mouseButton.button == Event::MouseButton::Left)
        isDragging = true;
}

void EventHandler::handleMouseRelease(const Event &event) {
    if (event.mouseButton.button == Event::MouseButton::Left)
        isDragging = false;
}

void EventHandler::handleKeyPress(const Event &event) {
    Window *window = _program->getWindow();

    if (event.keyEvent.key == Event::Key::Escape)
        window->close();

    // TODO: Create OpenGL context object, that will handle such functions
    if (event.keyEvent.key == Event::Key::D0)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    if (event.keyEvent.key == Event::Key::D1)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

/** Constructors */

EventHandler::EventHandler(Program *program)
    : _program(program), isDragging(false), oldX(0), oldY(0) {}

EventHandler::~EventHandler() {}

/** Public methods */

void EventHandler::handleEvents() {
    Window *window = _program->getWindow();

    while (Event event = window->poolEvents()) {
        switch (event.type) {
        case Event::Type::MouseMoved:
            handleMouseMovement(event);
            break;
        case Event::Type::MouseButtonPressed:
            handleMousePress(event);
            break;

        case Event::Type::MouseButtonReleased:
            handleMouseRelease(event);
            break;

        case Event::Type::KeyPressed:
            handleKeyPress(event);
            break;

        default:
            break;
        }
    }
}