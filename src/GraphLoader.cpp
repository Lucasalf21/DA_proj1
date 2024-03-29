//
// Created by lucasalf on 29-03-2024.
//

#include "GraphLoader.h"

GraphLoader::GraphLoader(Data* data, Graph<string>* g) {
    this->data = data;
    this->g = g;
}

void GraphLoader::loadVertex() {
    for (auto c : data->getCities()){
        g->addVertex(c->getCode());
    }
    for (auto r : data->getReservoirs()){
        g->addVertex(r->getCode());
    }
    for (auto s : data->getStations()){
        g->addVertex(s->getCode());
    }
}

void GraphLoader::loadPipes() {
    for (auto p : data->getPipes()){
        g->addEdge(p->getServiceA(), p->getServiceB(), p->getCapacity());
    }
}