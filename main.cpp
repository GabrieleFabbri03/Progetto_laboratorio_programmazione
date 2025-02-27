#include <iostream>
#include "Grid.h"
int main() {
    Grid grid (10, 50);
    std::cout<<"Griglia creata con dimensione: "<< grid.getGridSize() << "x" << grid.getGridSize() << std::endl;
    std::cout<<"Punto di partenza "<< grid.getStart().x << "x" << grid.getStart().y << std::endl;
    std::cout<<"Punto di arrivo "<< grid.getEnd().x << "x" << grid.getEnd().y << std::endl;

    return 0;
}
