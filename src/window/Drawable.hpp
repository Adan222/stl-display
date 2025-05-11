#pragma once

/**
 * This is a abstract class for drawable objects.
 *
 * Each object that inherit this class is able to be
 * displayed on the screen using OpenGL. Also, each
 * object that wants to be displayed should have their own
 * Array, vertex and element OpenGL buffers, however, this is
 * not mandatory and this object doesn't specify the
 * implementation.
 */
class Drawable {
  public:
    Drawable();
    ~Drawable();

    /**
     * Interface for drawing objects
     */
    virtual void draw() const = 0;
};