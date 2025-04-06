#include "Texture.hpp"

#include <stb_image.h>
#include <stdexcept>

#include "config.hpp"

Texture::Texture(unsigned int texture_unit) {
    _texture_unit = texture_unit;

    // Activate texture unit
    glActiveTexture(GL_TEXTURE0 + _texture_unit);
    glGenTextures(1, &_id);

    // TODO: Do we need to do this for each texture?
    stbi_set_flip_vertically_on_load(true);
}

Texture::~Texture() {}

void Texture::loadImage(const std::string &path) {
    const std::string texture_path = RESOURCE_DIR + std::string(path);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(texture_path.c_str(), &width, &height, &nrChannels, 0);
    if (data) {
        glActiveTexture(GL_TEXTURE0 + _texture_unit);
        glBindTexture(GL_TEXTURE_2D, _id);

        // Set texture data
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        throw std::runtime_error("Can't load texture: " + texture_path + "\n");
    }
    stbi_image_free(data);
}

void Texture::bindTexture() const {
    glActiveTexture(GL_TEXTURE0 + _texture_unit);
    glBindTexture(GL_TEXTURE_2D, _id);
}