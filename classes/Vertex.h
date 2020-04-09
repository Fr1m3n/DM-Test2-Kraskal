//
// Created by Roman on 09.04.2020.
//
#pragma once

#include "Graph.h"

class Graph;

class Vertex {
private:
    int num;
    int x;
    int y;

    Graph const * graph;
public:
    Vertex(int , int, int);
    static int dist(Vertex *, Vertex *);
    void addToGraph(Graph *);
    int getNum();
};

