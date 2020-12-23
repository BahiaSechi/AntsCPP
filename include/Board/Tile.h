/**
 * Address :
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 * Note :
 * This file is owned by an ENSICAEN student.  No portion of this
 * document may be reproduced, copied  or revised without written
 * permission of the authors.
 *
 * @author Mateo RABOTIN <mateo.rabotin@ecole.ensicaen.fr>
 * @author Bahia SECHI <bahia.sechi@ecole.ensicaen.fr>
 *
 * @date November 2020
 * @file main.cpp
 * @version 1.0
 *
 * @brief Blabla
 */

#ifndef ANTS_TILE_H
#define ANTS_TILE_H

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <Ants/Types/Ant.h>

class Ant;

enum class tile_type
{
    EMPTY, OBSTACLE, FOOD, COLONY
};

class Tile
{
protected:
    std::vector<Ant *> ants;
    sf::Vector2i       pos;
    tile_type          type;
    float              pheromones = 0.0f;
    bool               discovered = false;

public:
    Tile(std::vector<Ant *> ants, const sf::Vector2i &position, tile_type type);

    virtual ~Tile();

    /**
     * Slowly remove pheromones from the stock.
     */
    void evaporation();

    /**
     * Return weither the stock is at its maximum.
     * @return
     */
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

#endif //ANTS_TILE_H
