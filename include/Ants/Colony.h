//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTS_COLONY_H
#define ANTS_COLONY_H

#include <Ants/Types/Ant.h>
#include <Board/Tile.h>
#include <vector>

class Colony {
private:
    int food_stock;
    std::vector<Ant> ants;
    std::vector<Tile> colony_kingdom;
};


#endif //ANTS_COLONY_H
