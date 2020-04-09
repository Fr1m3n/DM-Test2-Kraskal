#include <iostream>
#include <set>
#include <vector>

#include "classes/Vertex.h"
#include "classes/Graph.h"

using namespace std;



signed main() {
    auto * p = new Vertex(1, 0, 0);
    auto * b = new Vertex(2, 2, 6);
    auto * g = new Graph();
    p->addToGraph(g);
    b->addToGraph(g);
    vector<Vertex> v = g->getVertexes();
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].getNum() << endl;
    }
    cout << Vertex::dist(p, b) << endl;

    return 0;
}