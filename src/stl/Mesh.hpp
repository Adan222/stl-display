#pragma once

/** STD */
#include <vector>

/** GLM */
#include <glm/vec3.hpp>

namespace stl {

class Mesh {
  private:
    const std::vector<glm::vec3> _vertices;

    const unsigned int _verticesCount;
    const unsigned int _rawDataCount;

  public:
    Mesh(const std::vector<glm::vec3> &vertices);
    ~Mesh();

    std::vector<glm::vec3> getVertices() const;
    std::vector<float> getRawData() const;

    unsigned int getVerticesCount() const;
    unsigned int getRawDataCount() const;
};

} // namespace stl