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

#ifndef ANTSPROJECT_WORKER_H
#define ANTSPROJECT_WORKER_H

#include <Ants/Types/Ant.h>
#include <Game.h>

class Worker : public virtual Ant {
private:
    bool has_food;
    bool major;
    float pheromones_stock;
    int minor_lifespan;

public:
    Worker(bool has_food, bool major, int pheromones_stock, int minor_lifespan, const Position &position);

    /**
     * While the worker is minor, do some basic movement. When it is major, go find some food.
     * The major worker will try to go as far as possible from the colony to find food.
     *
     * @param game
     */
    void play_turn(Game *game) override;

    /**
     * Search the tiles around for a tile with a high level of pheromone.
     * If one is found, return it otherwise the farest tile from the colony center with a little randomness.
     *
     * @param tiles_around
     * @return Tile *
     */
    Tile *pheromone_around(Tile **tiles_around, sf::Vector2i colony_pos);

    ~Worker();
};


#endif //ANTSPROJECT_WORKER_H
