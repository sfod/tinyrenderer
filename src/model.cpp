#include "model.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


Model::Model(const std::string &filename)
{
    std::ifstream in;
    in.open(filename, std::ifstream::in);
    if (in.fail()) {
        throw std::runtime_error("failed to open file");
    }

    char trash;
    std::string line;
    while (!in.eof()) {
        std::getline(in, line);
        std::istringstream iss(line);

        if (!line.compare(0, 2, "v ")) {
            iss >> trash;
            Vec3<float> v;
            for (int i = 0; i < 3; ++i) {
                iss >> v.raw[i];
            }
            vertices_.push_back(v);
        }
        else if (!line.compare(0, 2, "f ")) {
            iss >> trash;
            std::vector<int> f;
            int itrash, idx;
            while (iss >> idx >> trash >> itrash >> trash >> itrash) {
                idx--;
                f.push_back(idx);
            }
            faces_.push_back(f);
        }
    }
}

int Model::vertex_num() const
{
    return vertices_.size();
}

int Model::face_num() const
{
    return faces_.size();
}

Vec3<float> Model::vertex(int idx) const
{
    return vertices_.at(idx);
}

std::vector<int> Model::face(int idx) const
{
    return faces_.at(idx);
}
