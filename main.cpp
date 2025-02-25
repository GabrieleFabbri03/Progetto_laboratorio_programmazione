#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
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
    int getGridSize() const{ return gridSize;}
    int getCellSize() const{ return cellSize;}
    const sf::Vector2i& getStart()const{ return start;}
    const sf::Vector2i& getEnd()const{ return end;}
    bool isObstacle(int x, int y)const{return obstacles[x][y];}
    //aggiorna fine mappa
    void updateEnd() {
        end = sf::Vector2i(gridSize - 1, gridSize - 1);
    }
    void generateObstacles() {
        std::srand(std::time(nullptr));
        for (int i = 0; i < gridSize;++i)
            for (int j = 0; j < gridSize; ++j) {
                if ((i == start.x && j == start.y)||(i == end.x && j == end.y)) {
                    continue;
                }
                obstacles[i][j] = (std::rand() % 4 == 0);
            }
    }
    void setGridSize(int newSize){
        gridSize = newSize;
        obstacles.assign(gridSize, std::vector<bool>(gridSize, false));
        updateEnd();
        generateObstacles();
    }
};
int main() {
    Grid grid (10, 50);
    std::cout<<"Griglia creata con dimensione: "<< grid.getGridSize() << "x" << grid.getGridSize() << std::endl;
    return 0;
}
