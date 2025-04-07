#pragma once

template <typename T> struct ColorT {
    T r;
    T g;
    T b;
    T a;
};

typedef ColorT<float> Color;
