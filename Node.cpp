#include "Node.h"

Node::Node(sf::Vector2i pos, int g_cost, int h_cost, Node* par)
    : position(pos), g(g_cost), h(h_cost), parent(par){}
sf::Vector2i Node::getPosition() const {
    return position;
}

int Node::getG() const {
    return g;
}
int Node::getH() const {
    return h;
}
int Node::getF() const {
    return g + h;
}
Node* Node::getParent() const {
    return parent;
}

void Node::setG(int g_cost) {
    g = g_cost;
}

void Node::setH(int h_cost) {
    h = h_cost;
}

void Node::setParent(Node* par) {
    parent = par;
}

bool CompareNodes::operator()(const Node* a, const Node* b) const {
    return a->getF() > b->getF();
}
