#pragma once

template<typename T>
struct Vec2 {
    T x;
    T y;
};

template<typename T>
struct Vec3 {
    union {
        struct { T x, y, z; };
        T raw[3];
    };
};
