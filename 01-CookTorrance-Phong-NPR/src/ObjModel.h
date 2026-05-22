#pragma once
#include <vector>
#include <string>

struct Vertex {
    float px, py, pz;
    float nx, ny, nz;
};

class ObjModel {
public:
    std::vector<Vertex> vertices;
    bool load(const std::string& path);
};