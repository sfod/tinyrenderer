#pragma once

#include <vector>
#include <bits/stringfwd.h>
#include "geometry.h"

class Model {
public:
    explicit Model(const std::string &filename);

    int vertex_num() const;
    int face_num() const;

    Vec3<float> vertex(int idx) const;
    std::vector<int> face(int idx) const;

private:
    std::vector<Vec3<float>> vertices_;
    std::vector<std::vector<int>> faces_;
};
