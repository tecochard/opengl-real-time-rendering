#include "ObjModel.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool ObjModel::load(const std::string &path) {
    std::ifstream file(path);
    if (!file) {
        std::cerr << "Failed to open OBJ: " << path << "\n";
        return false;
    }

    std::vector<float> positions;
    std::vector<float> normals;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "v") {
            float x, y, z;
            ss >> x >> y >> z;
            positions.insert(positions.end(), {x, y, z});
        }

        else if (type == "vn") {
            float x, y, z;
            ss >> x >> y >> z;
            normals.insert(normals.end(), {x, y, z});
        }

        else if (type == "f") {
            for (int i = 0; i < 3; i++) {
                std::string token;
                ss >> token;

                int vi = 0, ni = 0, ti = 0;
                sscanf(token.c_str(), "%d/%d/%d", &vi, &ti, &ni);

                vi--;
                ni--;

                vertices.push_back({
                    positions[vi * 3 + 0],
                    positions[vi * 3 + 1],
                    positions[vi * 3 + 2],
                    normals[ni * 3 + 0],
                    normals[ni * 3 + 1],
                    normals[ni * 3 + 2],
                });
            }
        }
    }

    return true;
}