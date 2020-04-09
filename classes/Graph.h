//
// Created by Roman on 09.04.2020.
//
#pragma once

#include "Vertex.h"
#include <vector>

class Vertex;

class Graph {
private:
    int size;
    std::vector<Vertex> vertexes;
public:
    int getSize();
    void addVertex(Vertex *);
    std::vector<Vertex> getVertexes();
};

