#pragma once

#include <string>

/** GLAD go first */
#include <glad/glad.h>

class Shader {
public:
  enum class Type { Vertex, Fragment };

  Shader(Shader::Type type, const std::string &filename);
  ~Shader();

  const GLuint getID() const;

  void checkError() const;

private:
  GLuint _id;

  /**
   * Convert Shader type enum to OpenGL shader type
   */
  const int getGlVertextType(const Shader::Type t) const;
};
