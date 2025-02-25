#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
//creazione Griglia
class Grid {
private:
    int gridSize;
    int cellSize;
    sf::Vector2i start; //punto di partenza
    sf::Vector2i end;   //punto di arrivo
    std::vector<std::vector<bool>> obstacles; //matrice di ostacoli
public:
    //costruttore
    Grid(int gridSize, int cellSize)
    : gridSize(gridSize), cellSize(cellSize), start(0,0), end(gridSize - 1, gridSize - 1){
        setGridSize(gridSize);
    }
    void setGridSize(int newSize) {
        gridSize = newSize;
        obstacles = std::vector<std::vector<bool>>(gridSize,std::vector<bool>(gridSize,false));
    }
    int getGridSize() const{ return gridSize;}
    int getCellSize() const{ return cellSize;}
    const sf::Vector2i& getStart()const{ return start;}
    const sf::Vector2i& getEnd()const{ return end;}
    bool isObstacle(int x, int y)const{return obstacles[x][y];}
//aggiorna fine mappa
    void updateEnd() {
        end = sf::Vector2i(gridSize - 1, gridSize - 1);
    }