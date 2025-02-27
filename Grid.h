#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>
#include <vector>

class Grid {
private:
    int gridSize;
    int cellSize;
    sf::Vector2i start; //punto di partenza
    sf::Vector2i end;   //punto di arrivo
    std::vector<std::vector<bool>> obstacles; //matrice di ostacoli
public:
    Grid(int gridSize, int cellSize);

    int getGridSize() const;
    int getCellSize() const;
    const sf::Vector2i& getStart()const;
    const sf::Vector2i& getEnd()const;
    bool isObstacle(int x, int y) const;

    void updateEnd();
    void generateObstacles();
    void setGridSize(int newSize);
};
#endif
