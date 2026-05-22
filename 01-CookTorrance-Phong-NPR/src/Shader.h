#pragma once
#include <string>

class Shader {
public:
    unsigned int id;

    Shader(const char* vertexPath, const char* fragmentPath);
    void use() const;
};