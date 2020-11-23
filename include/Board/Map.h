//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTSPROJECT_MAP_H
#define ANTSPROJECT_MAP_H

#include <vector>

#include <SFML/System/Vector2.hpp>
#include <Board/Tile.h>

class Map {
private:
    sf::Vector2i dimension;
    int tile_size;
    std::vector<Tile> tiles;
};


#endif //ANTSPROJECT_MAP_H
