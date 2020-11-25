//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTSPROJECT_TILE_H
#define ANTSPROJECT_TILE_H

#include <SFML/System/Vector2.hpp>
#include <Ants/Types/Ant.h>

enum class tile_type {
    EMPTY, OBSTACLE, FOOD, COLONY
};

class Tile {
private:
    sf::Vector2<*Ant> ants;
    sf::Vector2i pos;
    tile_type type;

public:
    Tile(sf::Vector2<*Ant> ants, const sf::Vector2i &position, tile_type type);
    ~Tile();

    const sf::Vector2<*Ant> &getAnts() const;

    void setAnts(const sf::Vector2<*Ant> &ants);

    tile_type getType() const;

    void setType(tile_type type);
};

#endif //ANTSPROJECT_TILE_H
