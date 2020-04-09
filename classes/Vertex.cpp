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
    this->parent = this;
}

int Vertex::dist(Vertex *a, Vertex *b) {
    return abs((a->x - b->x)) + abs((a->y - b->y));
}

void Vertex::addToGraph(Graph *_graph) {
    this->graph = _graph;
    _graph->addVertex(this);
}

int Vertex::getNum() {
    return this->num;
}

void Vertex::connect(Vertex * v) {
    this->edges.push_back(*v);
    if (this->getSize() < v->getSize()) {
        this->getParent()->setParent(v->getParent());
        v->size += this->size;
    } else {
        v->getParent()->setParent(this->getParent());
        this->size += v->size;
    }
}

Vertex * Vertex::getParent() {
    if (this->parent == this) {
        return this;
    }
    return this->parent = this->parent->getParent();
}

int Vertex::getSize() {
    return this->size;
}

void Vertex::setParent(Vertex * v) {
    this->parent = v;
}

bool Vertex::isInOneComponent(Vertex * a, Vertex * b) {
    return a->getParent() == b->getParent();
}

