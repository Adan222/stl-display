// ShaderProgram.cpp
#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram() { this->_id = glCreateProgram(); }
ShaderProgram::~ShaderProgram() { glDeleteProgram(this->_id); }

void ShaderProgram::attacheShader(const Shader &shader) const {
    glAttachShader(this->_id, shader.getID());
}

void ShaderProgram::useProgram() const { glUseProgram(this->_id); }

void ShaderProgram::linkShaders() const { glLinkProgram(this->_id); }

/** Set Unform functions */

void ShaderProgram::setUniformBool(const std::string &name, bool value) const {
    const int location = glGetUniformLocation(this->_id, name.c_str());
    glUniform1i(location, (int)value);
}

void ShaderProgram::setUniformInt(const std::string &name, int value) const {
    const int location = glGetUniformLocation(this->_id, name.c_str());
    glUniform1i(location, value);
}

/** Floats */

void ShaderProgram::setUniform1f(const std::string &name, float v0) const {
    const int location = glGetUniformLocation(this->_id, name.c_str());
    glUniform1f(location, v0);
}

void ShaderProgram::setUniform2f(const std::string &name, float v0, float v1) const {
    const int location = glGetUniformLocation(this->_id, name.c_str());
    glUniform2f(location, v0, v1);
}

void ShaderProgram::setUniform3f(const std::string &name, float v0, float v1, float v2) const {
    const int location = glGetUniformLocation(this->_id, name.c_str());
    glUniform3f(location, v0, v1, v2);
}

void ShaderProgram::setUniform4f(
    const std::string &name, float v0, float v1, float v2, float v3) const {
    const int location = glGetUniformLocation(this->_id, name.c_str());
    glUniform4f(location, v0, v1, v2, v3);
}

/** Matrices */

void ShaderProgram::setUniformMatrix4f(const std::string &name, const float *v) {
    const int location = glGetUniformLocation(this->_id, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, v);
}
