#include <cmath>
#include <iostream>
#include <string>

/**
 * OpenGL
 * NOTE: GLAD library must go first and before other OpenGL libs
 */
#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include "shader.hpp"
#include "shader_program.hpp"

struct VertexPosition {
    float x;
    float y;
    float z;
};

struct VertexColor {
    float r;
    float g;
    float b;
};

struct Vertex {
    VertexPosition position;
    VertexColor color;
};

// Callback function to resize the OpenGL viewport when the window is resized
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    // Set OpenGL version to 3.3 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL Test", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    // Load OpenGL function pointers with GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD!" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Create shaders
    Shader fragmentShader(Shader::Type::Fragment, "fragment.frag");
    fragmentShader.checkError();
    Shader vertexShader(Shader::Type::Vertex, "vertex.vert");
    vertexShader.checkError();

    // Programs
    ShaderProgram shaderProgram;
    shaderProgram.attacheShader(vertexShader);
    shaderProgram.attacheShader(fragmentShader);
    shaderProgram.linkShaders();

    /** Create right triangle  */
    Vertex right_triangle_vertices[] = {
        // Position               // Color
        { { -0.5f, -0.5f, 0.0f }, { 1.0f, 0.0f, 0.0f } }, // Top
        { { 0.5f, -0.5f, 0.0f }, { 0.0f, 1.0f, 0.0f } },  // Right
        { { 0.0f, 0.5f, 0.0 }, { 0.0f, 0.0f, 1.0f } },    // Left
    };

    // VAO
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(right_triangle_vertices),
                 right_triangle_vertices,
                 GL_STATIC_DRAW);

    // Configure attributes
    // Vertex position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);
    glEnableVertexAttribArray(0);

    // Vertex color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)sizeof(VertexPosition));
    glEnableVertexAttribArray(1);

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.6f, 0.6f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw triangle
        shaderProgram.useProgram();
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        if (glfwGetKey(window, GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(window, GLFW_TRUE);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
}
