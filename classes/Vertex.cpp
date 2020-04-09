//
// Created by Roman on 09.04.2020.
//

#include "Vertex.h"
#include <cmath>

Vertex::Vertex(int num, int x, int y) {
    this->num = num;
    this->x = x;
    this->y = y;
    this->graph = nullptr;
}

int Vertex::dist(Vertex *a, Vertex *b) {
    return abs((a->x - b->x) + (a->y - b->y));
}

void Vertex::addToGraph(Graph *_graph) {
    this->graph = _graph;
    _graph->addVertex(this);
}

int Vertex::getNum() {
    return this->num;
}

