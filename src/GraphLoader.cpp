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
        g->addVertex(c.second->getCode());
    }
    for (auto r : data->getReservoirs()){
        g->addVertex(r.second->getCode());
    }
    for (auto s : data->getStations()){
        g->addVertex(s.second->getCode());
    }
}

void GraphLoader::loadPipes() {
    for (auto p : data->getPipes()){
        if (p->getDirection() == 1) {
            g->addEdge(p->getServiceA(), p->getServiceB(), p->getCapacity());
        }
        else{
            g->addBidirectionalEdge(p->getServiceA(), p->getServiceB(), p->getCapacity());
        }
    }
}