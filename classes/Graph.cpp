//
// Created by Roman on 09.04.2020.
//

#include "Graph.h"

void Graph::addVertex(Vertex *v) {
    this->size++;
    this->vertexes.push_back(*v);
}

int Graph::getSize() {
    return this->size;
}

std::vector<Vertex> Graph::getVertexes() {
    return this->vertexes;
}
