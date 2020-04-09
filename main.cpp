#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <algorithm>
#include <windows.h>

#include "classes/Vertex.h"
#include "classes/Graph.h"

using namespace std;

vector<Vertex *> readVertexes(string fileName) {
    vector<Vertex *> v;

    ifstream in(fileName);
    if (in.is_open()) {

        int x;
        int y;
        int i = 1;
        while (in >> x >> y) {
            v.push_back(new Vertex(i++, x, y));
        }
    }
    in.close();
    return v;
}

bool compare(Edge * a, Edge * b) {
    return a->getWeight() < b->getWeight();
}

signed main() {
    auto * g = new Graph();


    cout << "Считываем с файла. ";
    g->addAll(readVertexes("input"));
    cout << "Считали." << endl;

    cout << "Получаем список всех рёбер. ";
    vector<Edge *> edges = g->connectAll();
    cout << "Готово!" << endl;

    cout << "Сортируем рёбра. ";
    sort(edges.begin(), edges.end(), compare);
    cout << "Сделано!" << endl;

    cout << "Применяем алгоритм Краскала";
    vector<Edge *> res;
    for (int i = 0; i < edges.size(); i++) {
        Vertex * a = edges[i]->getFirst();
        Vertex * b = edges[i]->getSecond();
        if (Vertex::isInOneComponent(a, b)) {
            continue;
        }

        a->connect(b);
        res.push_back(edges[i]);
        if (res.size() == g->getSize() - 1) {
            break;
        }
    }
    cout << "Применили!" << endl;

    int resWeight = 0;
    cout << "Список рёбер, входящих в минимальное связывающее дерево: " << endl;
    for(auto edge: res) {
        cout << "{e" << edge->getFirst()->getNum() << "; e" << edge->getSecond()->getNum() << '}' << endl;
        resWeight += edge->getWeight();
    }
    cout << "Суммарный вес рёбер, входящих в МСД: " << resWeight << endl;

    return 0;
}