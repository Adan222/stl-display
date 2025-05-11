#pragma once

#include "window/Event.hpp"

// Predefine Program class
class Program;

/**
 * This class is responsible for handling widnow events
 * and holding state related with this
 */
class EventHandler {
  private:
    Program *_program;

    /** Handlers */
    void handleMouseMovement(const Event &event);
    void handleMousePress(const Event &event);
    void handleMouseRelease(const Event &event);
    void handleKeyPress(const Event &event);

    /** Variables */
    bool isDragging;
    int oldX;
    int oldY;

  public:
    EventHandler(Program *program);
    ~EventHandler();

    void handleEvents();
};