#pragma once

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
