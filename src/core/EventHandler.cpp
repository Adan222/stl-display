#include "core/EventHandler.hpp"

/** Core */
#include "core/Renderer.hpp"

/** Lib OpenGL */
#include "window/Event.hpp"
#include "window/Window.hpp"

/** Private methods */

void EventHandler::handleMouseMovement(const Event &event) {
    if (isDragging) {
        auto x = event.mouseMove.x;
        auto y = event.mouseMove.y;

        _renderer->handleDrag(oldX, oldY, x, y);

        oldX = x;
        oldY = y;
    }
}

void EventHandler::handleMousePress(const Event &event) {
    if (event.mouseButton.button == Event::MouseButton::Left) {
        isDragging = true;

        oldX = event.mouseButton.x;
        oldY = event.mouseButton.y;
    }
}

void EventHandler::handleMouseRelease(const Event &event) {
    if (event.mouseButton.button == Event::MouseButton::Left)
        isDragging = false;
}

void EventHandler::handleKeyPress(const Event &event) {
    Window *window = _renderer->getWindow();

    if (event.keyEvent.key == Event::Key::Escape)
        window->close();

    // TODO: Create OpenGL context object, that will handle such functions
    if (event.keyEvent.key == Event::Key::D0)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    if (event.keyEvent.key == Event::Key::D1)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

/** Constructors */

EventHandler::EventHandler(Renderer *renderer)
    : _renderer(renderer), isDragging(false), oldX(0), oldY(0) {}

EventHandler::~EventHandler() {}

/** Public methods */

void EventHandler::handleEvents() {
    Window *window = _renderer->getWindow();

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