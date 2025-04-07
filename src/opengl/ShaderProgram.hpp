#pragma once

/** GLAD go first */
#include <glad/glad.h>

#include "Shader.hpp"

class ShaderProgram {
  private:
    GLuint _id;

  public:
    ShaderProgram();
    ~ShaderProgram();

    void attacheShader(const Shader &shader) const;

    void useProgram() const;
    void linkShaders() const;

    /**
     * Set Uniform variable functions by type
     */
    void setUniformBool(const std::string &name, bool value) const;

    /** Ints */
    void setUniformInt(const std::string &name, int value) const;

    /** Floats */
    void setUniform1f(const std::string &name, float v0) const;
    void setUniform2f(const std::string &name, float v0, float v1) const;
    void setUniform3f(const std::string &name, float v0, float v1, float v2) const;
    void setUniform4f(const std::string &name, float v0, float v1, float v2, float v3) const;

    /** Matrices */
    void setUniformMatrix4f(const std::string &name, const float *v) const;
};
