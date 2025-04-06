# Create a static library for glad
add_library(stb STATIC src/stb_image.cpp)

target_include_directories(stb PUBLIC include)
target_compile_definitions(stb PRIVATE GLAD_GLAPI_EXPORT)