//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTSPROJECT_TILE_H
#define ANTSPROJECT_TILE_H

#include <SFML/System/Vector2.hpp>

class Tile {
private:
    int ant_count;
    sf::Vector2i pos;

public:
    Tile(int ant_count, sf::Vector2i position);
};


#endif //ANTSPROJECT_TILE_H
