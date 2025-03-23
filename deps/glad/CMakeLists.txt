# Create a static library for glad
add_library(glad STATIC src/glad.c)

target_include_directories(glad PUBLIC include)
target_compile_definitions(glad PRIVATE GLAD_GLAPI_EXPORT)