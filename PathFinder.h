#ifndef PATHFINDER_H
#define PATHFINDER_H
#include <vector>
#include <queue>
#include <SFML/System/Vector2.hpp>
#include "Grid.h"
class Node {
public:
    sf::Vector2i position;
    int g,h;
    Node* parent;

    Node(sf::Vector2i pos, int gCost,int hCost, Node* parent = nullptr)
        : position(pos), g(gCost), h(hCost), parent(parent){}

    int getFCost() const { return g + h ;}
};
class CompareNodes {
public:
    bool operator()(const Node* a, const Node* b) const {
        return a->getFCost() > b->getFCost();
    }
};
class Pathfinder {
private:
    const Grid& grid;

public:
    Pathfinder(const Grid& grid);
    std::vector<sf::Vector2i> findPath();
};

#endif
