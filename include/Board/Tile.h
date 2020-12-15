//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTSPROJECT_TILE_H
#define ANTSPROJECT_TILE_H

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <Ants/Types/Ant.h>

class Ant;

enum class tile_type {
    EMPTY, OBSTACLE, FOOD, COLONY
};

class Tile {
protected:
    std::vector<Ant *> ants;
    sf::Vector2i pos;
    tile_type type;
    float pheromones = 0.0f;
    bool discovered = false;

public:
    Tile(std::vector<Ant *> ants, const sf::Vector2i &position, tile_type type);
    ~Tile();

    void evaporation();

    bool pheromone_max();

    const sf::Vector2i &getPos() const;

    const std::vector<Ant *> &getAnts() const;

    void setAnts(const std::vector<Ant *> &ants);

    tile_type getType() const;

    float getPheromones() const;

    void setPheromones(float pheromones);

    bool isDiscovered() const;

    void setDiscovered(bool discovered);
};

#endif //ANTS00.
// PROJECT_TILE_H
