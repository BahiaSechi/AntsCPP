//
// Created by kyojin on 23/11/2020.
//

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
