#include "Grid.h"
#include <cstdlib>
#include <ctime>

Grid::Grid(int gridSize, int cellSize)
    : gridSize(gridSize), cellSize(cellSize), start(0,0), end(gridSize - 1, gridSize - 1){
    setGridSize(gridSize);
}
int Grid::getGridSize() const{ return gridSize;}
int Grid::getCellSize() const{ return cellSize;}
const sf::Vector2i& Grid::getStart()const{ return start;}
const sf::Vector2i& Grid::getEnd()const{ return end;}
bool Grid::isObstacle(int x, int y)const{return obstacles[x][y];}

void Grid::updateEnd() {
    end = sf::Vector2i(gridSize - 1, gridSize - 1);
}

void Grid::generateObstacles() {
    std::srand(std::time(nullptr));
    for (int i = 0; i < gridSize;++i)
        for (int j = 0; j < gridSize; ++j) {
            if ((i == start.x && j == start.y)||(i == end.x && j == end.y)) {
                continue;
            }
            obstacles[i][j] = (std::rand() % 4 == 0);
        }
}
void Grid::setGridSize(int newSize){
    gridSize = newSize;
    obstacles.assign(gridSize, std::vector<bool>(gridSize, false));
    updateEnd();
    generateObstacles();
}
