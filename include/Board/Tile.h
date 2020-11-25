//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTSPROJECT_TILE_H
#define ANTSPROJECT_TILE_H

#include <SFML/System/Vector2.hpp>

enum class tile_type {
    EMPTY, OBSTACLE, FOOD, COLONY
};

class Tile {
private:
    int ant_count;
    sf::Vector2i pos;
    tile_type type;

public:
    Tile(int ant_count, const sf::Vector2i &position, tile_type type);
    ~Tile();

    int getAntCount() const;

    void setAntCount(int antCount);

    const sf::Vector2i &getPos() const;

    void setPos(const sf::Vector2i &pos);

    tile_type getType() const;

    void setType(tile_type type);
};

#endif //ANTSPROJECT_TILE_H
