#include "PathFinder.h"

Pathfinder::Pathfinder(const Grid&  grid): grid(grid){}
std::vector<sf::Vector2i>Pathfinder::findPath() {
    std::vector<sf::Vector2i>path;
    std::priority_queue<Node*, std::vector<Node*>, CompareNodes> openList;
    std::vector<std::vector<bool>> closed(grid.getGridSize(), std::vector<bool>(grid.getGridSize(), false));

    Node* startNode = new Node(grid.getStart(), 0, abs(grid.getStart().x - grid.getEnd().x) + abs(grid.getStart().y - grid.getEnd().y));
    openList.push(startNode);

    while (!openList.empty()) {
        Node* current = openList.top();
        openList.pop();

        if (current->position == grid.getEnd()) {
            while (current) {
                path.insert(path.begin(), current->position);
                current = current->parent;
            }
            break;
        }

        closed[current->position.x][current->position.y] = true;

        std::vector<sf::Vector2i> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto& dir : directions) {
            sf::Vector2i neighborPos = current->position + dir;
            if (neighborPos.x >= 0 && neighborPos.x < grid.getGridSize() &&
                neighborPos.y >= 0 && neighborPos.y < grid.getGridSize() &&
                !closed[neighborPos.x][neighborPos.y] && !grid.isObstacle(neighborPos.x, neighborPos.y)) {

                int gCost = current->g + 1;
                int hCost = abs(neighborPos.x - grid.getEnd().x) + abs(neighborPos.y - grid.getEnd().y);
                openList.push(new Node(neighborPos, gCost, hCost, current));
                }
        }
    }

    return path;
}
