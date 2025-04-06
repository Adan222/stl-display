#include "Program.hpp"

#include <stdexcept>

// OpenGL classes
#include "ElementBufferObject.hpp"
#include "Shader.hpp"
#include "ShaderProgram.hpp"
#include "Texture.hpp"
#include "VertexArrayObject.hpp"
#include "VertexBufferObject.hpp"

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

struct VertexTextureCoordinates {
    float s;
    float t;
};

struct Vertex {
    VertexPosition position;
    VertexColor color;
    VertexTextureCoordinates texture;
};

Program::Program(unsigned int width, unsigned int height)
    : _window_width(width), _widnow_height(height) {
    initOpenGL();
}

Program::~Program() {
    glfwDestroyWindow(_window);
    glfwTerminate();
}

void Program::initOpenGL() {
    // Initialize GLFW
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW!");

    // Set OpenGL version to 3.3 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    _window = glfwCreateWindow(_window_width, _widnow_height, "OpenGL Test", nullptr, nullptr);
    if (!_window)
        throw std::runtime_error("Failed to create GLFW window!");

    // Init OpenGL context
    glfwMakeContextCurrent(_window);

    // Load OpenGL function pointers with GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize GLAD!");

    glViewport(0, 0, _window_width, _widnow_height);

    /** ===== GLFW Callbacks ===== */
    auto framebuffer_size_callback = [](GLFWwindow *window, int width, int height) -> void {
        glViewport(0, 0, width, height);
    };
    glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);
}

void Program::processInput() {
    if (glfwGetKey(_window, GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(_window, GLFW_TRUE);

    if (glfwGetKey(_window, GLFW_KEY_0))
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    if (glfwGetKey(_window, GLFW_KEY_1))
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Program::run() {
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

    // VAO
    VertexArrayObject vao;
    vao.bind();

    // VBO
    Vertex rectangleVertices[] = {
        // Position              // Color
        { { -0.5f, 0.5f, 0.0f }, { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f } }, // Left Top
        { { 0.5f, 0.5f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f } },  // Right Top

        { { -0.5f, -0.5f, 0.0 }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 0.0f } }, // Left Bottom
        { { 0.5f, -0.5f, 0.0 }, { 1.0f, 0.0f, 1.0f }, { 1.0f, 0.0f } },  // Right Bottom
    };

    VertexBufferObject vbo;
    vbo.setData(rectangleVertices, sizeof(rectangleVertices));

    // EBO
    unsigned int indices[] = {
        0, 1, 2, // Upper triangle
        1, 2, 3  // Lower triangle
    };

    ElementBufferObject ebo;
    ebo.setData(indices, sizeof(indices));

    // Configure attributes
    // Vertex position
    AttributeConfiguration vertexConfig = { .index = 0,
                                            .size = 3,
                                            .dataType = AttributeConfiguration::Type::FLOAT,
                                            .normalize = false,
                                            .stride = sizeof(Vertex),
                                            .startPointer = 0 };
    vao.configureAttribute(vertexConfig);

    // Vertex color
    AttributeConfiguration colorConfig = { .index = 1,
                                           .size = 3,
                                           .dataType = AttributeConfiguration::Type::FLOAT,
                                           .normalize = false,
                                           .stride = sizeof(Vertex),
                                           .startPointer = sizeof(VertexPosition) };
    vao.configureAttribute(colorConfig);

    // Vertex color
    AttributeConfiguration textureConfig = { .index = 2,
                                             .size = 2,
                                             .dataType = AttributeConfiguration::Type::FLOAT,
                                             .normalize = false,
                                             .stride = sizeof(Vertex),
                                             .startPointer = 6 * sizeof(float) };
    vao.configureAttribute(textureConfig);

    // Textures
    Texture brick_texture(0);
    brick_texture.loadImage("/woodencontainer.png");

    Texture face_texture(1);
    face_texture.loadImage("/awesomeface.png");

    shaderProgram.useProgram();
    shaderProgram.setUniformInt("Texture0", 0);
    shaderProgram.setUniformInt("Texture1", 1);

    while (!glfwWindowShouldClose(_window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        processInput();

        // Draw triangle
        shaderProgram.useProgram();
        vao.bind();
        brick_texture.bindTexture();
        face_texture.bindTexture();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}