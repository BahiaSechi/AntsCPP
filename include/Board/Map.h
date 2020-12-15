//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTSPROJECT_MAP_H
#define ANTSPROJECT_MAP_H

#include <vector>
#include <ostream>
#include <mutex>

#include <SFML/System/Vector2.hpp>
#include <Board/Tile.h>

class Tile;

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

public:
    Map(int height, int width, int colony_food, int big_food_source_count);

    ~Map();

    void generate();

    Tile ** look_around(int x, int y) const;

    void diffusion(Tile tile);

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

#endif //ANTSPROJECT_MAP_H
