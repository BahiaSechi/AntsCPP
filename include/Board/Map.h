//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTSPROJECT_MAP_H
#define ANTSPROJECT_MAP_H

#include <vector>

#include <SFML/System/Vector2.hpp>
#include <Board/Tile.h>
#include <ostream>

class Map {
private:
    sf::Vector2i dimension;
    int tile_size;
    Tile ***tiles;
    int big_food_source_count;

public:
    Map(int height, int width, int tile_size, int big_food_source_count);
    ~Map();

    friend std::ostream &operator<<(std::ostream &os, const Map &map);
};


#endif //ANTSPROJECT_MAP_H
