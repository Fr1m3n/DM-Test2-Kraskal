//
// Created by Roman on 09.04.2020.
//

#include "Graph.h"
#include <vector>
#include <iostream>

void Graph::addVertex(Vertex *v) {
    this->size++;
    this->vertexes.push_back(v);
}

int Graph::getSize() {
    return this->size;
}

std::vector<Vertex *> Graph::getVertexes() {
    return this->vertexes;
}

std::vector<Edge *> Graph::connectAll() {
    std::vector<Vertex *> ve = this->getVertexes();
    std::vector<Edge *> ed;
    ed.clear();
    for(int i = 0; i < ve.size(); i++) {
        for(int j = i + 1; j < ve.size(); j++) {
            if (i == j) {
                continue;
            }
            ed.push_back(new Edge(ve[i], ve[j]));
        }
    }
    return ed;

}

void Graph::addAll(std::vector <Vertex *> _vertexes) {
    for (auto item: _vertexes) {
        item->addToGraph(this);
    }
}
