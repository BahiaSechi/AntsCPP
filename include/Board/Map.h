//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTS_MAP_H
#define ANTS_MAP_H

#include <vector>
#include <ostream>
#include <mutex>

#include <SFML/System/Vector2.hpp>
#include <Board/Tile.h>

class Tile;

class Map
{
private:
    sf::Vector2i dimension;
    Tile         ***tiles;
    int          colony_food;
    int          big_food_source_count;
    bool         is_generated;
    std::mutex   mtx;

    int nbNeighbors(int y, int x);

    bool reduceFoodFrom(Tile *tile, float amount);

public:
    Map(int height, int width, int colony_food, int big_food_source_count);

    void generate();

    ~Map();

    bool reduceFood(int x, int y, float amount);

    int getColonyFood() const;

    friend std::ostream &operator<<(std::ostream &os, const Map &map);

    const sf::Vector2i &getDimension() const;

    void setDimension(const sf::Vector2i &dimension);

    Tile ***getTiles() const;

    void setTiles(Tile ***tiles);

    Tile *setTile(int x, int y, Tile *tile);

    Tile * getTile(int x, int y) const;

    void setColonyFood(int colonyFood);

    bool isGenerated() const;
};

#endif //ANTS_MAP_H
