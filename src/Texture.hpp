#pragma once

#include <string>

#include <glad/glad.h>

class Texture {
  private:
    GLuint _id;
    GLuint _texture_unit;

  public:
    Texture(unsigned int texture_unit);
    ~Texture();

    void loadImage(const std::string &path);

    void bindTexture() const;
};