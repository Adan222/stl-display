#include "Event.hpp"

Event::Event(Type t) : type(t) {}

Event::~Event() {}

/** Operators */

Event::operator bool() const { return type != Event::Type::None; }