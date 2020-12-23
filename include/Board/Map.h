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
    sf::Vector2i colony_pos;
    Tile         ***tiles;
    int          colony_food;
    int          big_food_source_count;
    bool         is_generated;
    std::mutex   mtx;

    int nbNeighbors(int y, int x);

    bool reduceFoodFrom(Tile *tile, float amount);

public:
    Map(int height, int width, int colony_food, int big_food_source_count);

    ~Map();

    void generate();

    /**
     * Find and return the tiles around the given pos. Attention, the returned array is dynamically allocated !
     *
     * @param x
     * @param y
     * @return Tiles around x and y, dynamically allocated
     */
    Tile **look_around(int x, int y);

    /**
     * Spread pheromones accross tile surrounding.
     *
     * @param tile
     */
    void diffusion(Tile tile);

    /**
     * Reduce the food stock of a tile.
     *
     * @param x
     * @param y
     * @param amount
     * @return
     */
    bool reduceFood(int x, int y, float amount);

    int getColonyFood() const;

    friend std::ostream &operator<<(std::ostream &os, const Map &map);

    const sf::Vector2i &getDimension() const;

    void setDimension(const sf::Vector2i &dimension);

    Tile ***getTiles() const;

    void setTiles(Tile ***tiles);

    void setTile(int x, int y, Tile *tile);

    Tile * getTile(int x, int y);

    void setColonyFood(int colonyFood);

    bool isGenerated() const;
};

#endif //ANTS_MAP_H
