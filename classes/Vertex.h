//
// Created by Roman on 09.04.2020.
//
#pragma once

#include "Graph.h"
#include <vector>

class Graph;

class Vertex {
private:
    int num;
    Vertex * parent;
    int size = 1;
    int x;
    int y;

    std::vector<Vertex> edges;
    Graph const * graph;

    void setParent(Vertex *);
public:
    Vertex(int , int, int);
    static int dist(Vertex *, Vertex *);
    void addToGraph(Graph *);
    int getNum();
    void connect(Vertex *);
    Vertex * getParent();
    int getSize();

    static bool isInOneComponent(Vertex *, Vertex *);
};

