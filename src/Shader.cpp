#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

/** GLAD go first */
#include <glad/glad.h>

/** File we define */
#include "Shader.hpp"

#include "config.hpp"

Shader::Shader(Shader::Type type, const std::string &filename) {
    std::ifstream shader_file(SHADER_DIR + filename);
    if (!shader_file)
        throw std::runtime_error("Unable to open: " + filename);

    // Read entire shader
    std::ostringstream buffer;
    buffer << shader_file.rdbuf();

    const std::string data = buffer.str();
    const char *shader_data = data.c_str();

    const int gl_shader_type = getGlVertextType(type);
    this->_id = glCreateShader(gl_shader_type);

    glShaderSource(this->_id, 1, &shader_data, NULL);
    glCompileShader(this->_id);
}

Shader::~Shader() { glDeleteShader(this->_id); }

const GLuint Shader::getID() const { return this->_id; }

void Shader::checkError() const {
    int success;
    char infoLog[512];

    glGetShaderiv(this->_id, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(this->_id, 512, NULL, infoLog);
        std::string error = "ERROR::SHADER::COMPILATION_FAILED\n" + std::string(infoLog);
        throw std::runtime_error(error);
    }
}

const int Shader::getGlVertextType(Shader::Type t) const {
    switch (t) {
    case Shader::Type::Fragment:
        return GL_FRAGMENT_SHADER;
    case Shader::Type::Vertex:
        return GL_VERTEX_SHADER;
    }
    throw std::runtime_error("Unknown shader type");
}
