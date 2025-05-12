#include "Mesh.hpp"

/** Constructors */

stl::Mesh::Mesh(const std::vector<glm::vec3> &vertices) : _vertices(vertices) {}

stl::Mesh::~Mesh() {}

/** Public methods */

std::vector<glm::vec3> stl::Mesh::getVertices() const { return _vertices; }

std::vector<float> stl::Mesh::getRawData() const {
    const std::vector<glm::vec3> rawVertices = getVertices();

    std::vector<float> rawFloats;
    for (const glm::vec3 &v : rawVertices) {
        rawFloats.emplace_back(v.x);
        rawFloats.emplace_back(v.y);
        rawFloats.emplace_back(v.z);
    }

    return rawFloats;
}