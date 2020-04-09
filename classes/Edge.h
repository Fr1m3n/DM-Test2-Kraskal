//
// Created by Roman on 09.04.2020.
//

#ifndef INC_111_EDGE_H
#define INC_111_EDGE_H

#include "Vertex.h"

class Vertex;

class Edge {
private:
    Vertex * first;
    Vertex * second;
    int weight;
public:
    Edge(Vertex *, Vertex *);
    int getWeight();
    Vertex * getFirst();
    Vertex * getSecond();
};


#endif //INC_111_EDGE_H
