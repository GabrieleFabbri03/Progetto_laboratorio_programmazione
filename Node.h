#ifndef NODE_H
#define NODE_H
#include<SFML/System/Vector2.hpp>
class Node {
public:
    Node(sf::Vector2i pos,int g_cost, int h_cost, Node* par = nullptr);

    sf::Vector2i getPosition() const;
    int getG() const;
    int getH() const;
    int getF() const;
    Node* getParent () const;

    void setG(int g_const);
    void setH(int h_const);
    void setParent(Node *par);
private:
    sf::Vector2i position;
    int g,h;
    Node* parent;
};

class CompareNodes {
public:
    bool operator()(const Node* a, const Node* b) const;
};

#endif //NODE_H
