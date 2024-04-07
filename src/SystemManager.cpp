//
// Created by lucasalf on 06-04-2024.
//

#include "SystemManager.h"
using namespace std;

SystemManager::SystemManager() {}

// Function to test the given vertex 'w' and visit it if conditions are met
void testAndVisit(std::queue<Vertex<string>*>& q, Edge<string>* e, Vertex<string>* w, double residual) {
    // Check if the vertex 'w' is not visited and there is residual capacity
    if (!w->isVisited() && residual > 0) {
        // Mark 'w' as visited, set the path through which it was reached, and enqueue it
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

// Function to find an augmenting path using Breadth-First Search
bool findAugmentingPath(Graph<string>* g, Vertex<string>* s, Vertex<string>* t) {
    // Mark all vertices as not visited
    for (auto v : g->getVertexSet()) {
        v->setVisited(false);
    }
    // Mark the source vertex as visited and enqueue it
    s->setVisited(true);
    std::queue<Vertex<string>*> q;
    q.push(s);
    // BFS to find an augmenting path
    while (!q.empty() && !t->isVisited()) {
        auto v = q.front();
        q.pop();
        // Process outgoing edges
        for (auto e : v->getAdj()) {
            testAndVisit(q, e, e->getDest(), e->getWeight() - e->getFlow());
        }
        // Process incoming edges
        for (auto e : v->getIncoming()) {
            testAndVisit(q, e, e->getOrig(), e->getFlow());
        }
    }
    // Return true if a path to the target is found, false otherwise
    return t->isVisited();
}

// Function to find the minimum residual capacity along the augmenting path
double findMinResidualAlongPath(Vertex<string>* s, Vertex<string>* t) {
    double f = INF;
    // Traverse the augmenting path to find the minimum residual capacity
    for (auto v = t; v != s;) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            f = std::min(f, e->getWeight() - e->getFlow());
            v = e->getOrig();
        }
        else {
            f = std::min(f, e->getFlow());
            v = e->getDest();
        }
    }
    // Return the minimum residual capacity
    return f;
}

// Function to augment flow along the augmenting path with the given flow value
void augmentFlowAlongPath(Vertex<string>* s, Vertex<string>* t, double f) {
    // Traverse the augmenting path and update the flow values accordingly
    for (auto v = t; v != s;) {
        auto e = v->getPath();
        double flow = e->getFlow();
        if (e->getDest() == v) {
            e->setFlow(flow + f);
            v = e->getOrig();
        }
        else {
            e->setFlow(flow - f);
            v = e->getDest();
        }
    }
}

// Main function implementing the Edmonds-Karp algorithm with super source and super sink
void SystemManager::edmondsKarp(Graph<string> g, Data* data) {
    g.addVertex("Super Source");
    g.addVertex("Super Sink");

    Vertex<string>* superSource = g.findVertex("Super Source");
    Vertex<string>* superSink = g.findVertex("Super Sink");

    // Connect super source to all vertices with prefix 'R'
    for (auto v : g.getVertexSet()) {
        if (v->getInfo()[0] == 'R') {
            superSource->addEdge(v, data->findReservoir(v->getInfo())->getMaxDelivery());
        }
    }

    // Connect all vertices with prefix 'C' to the super sink
    for (auto v : g.getVertexSet()) {
        if (v->getInfo()[0] == 'C') {
            v->addEdge(superSink, data->findCity(v->getInfo())->getDemand());
        }
    }

    // Initialize flow on all edges to 0
    for (auto v : g.getVertexSet()) {
        for (auto e : v->getAdj()) {
            e->setFlow(0);
        }
    }

    // While there is an augmenting path, augment the flow along the path
    while (findAugmentingPath(&g, superSource, superSink)) {
        double f = findMinResidualAlongPath(superSource, superSink);
        augmentFlowAlongPath(superSource, superSink, f);
    }
}