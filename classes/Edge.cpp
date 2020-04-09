//
// Created by Roman on 09.04.2020.
//

#include "Edge.h"

Edge::Edge(Vertex * a, Vertex * b) {
    this->first = a;
    this->second = b;
    this->weight = Vertex::dist(a, b);
}

int Edge::getWeight() {
    return this->weight;
}

Vertex *Edge::getSecond() {
    return this->second;
}

Vertex *Edge::getFirst() {
    return this->first;
}
