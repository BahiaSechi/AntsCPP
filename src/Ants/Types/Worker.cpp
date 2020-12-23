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

#include <Ants/Types/Worker.h>
#include <constants.h>

Worker::Worker(bool has_food, bool major, int pheromones_stock, int minor_lifespan, const Position &position) :
        Ant(Constants::Ant::LIFESPAN, position, Alimentation(0.1, 1), WORKER), minor_lifespan(15)
{}

Worker::~Worker()
{}

void Worker::play_turn(Game *game)
{
    /* Initialize variables. */
    auto ant_pos     = this->position.getPos();
    int  x_pos       = ant_pos.x;
    int  y_pos       = ant_pos.y;
    auto stack       = this->position.getPosStack();
    auto map         = game->getMap();
    int  x_dimension = map->getDimension().x;
    int  y_dimension = map->getDimension().y;
    Tile *tile       = map->getTile(x_pos, y_pos);

    //TODO Si plus de pheromones autour, on continue dans la même direction

    if (this->has_food) {
        /* Put pheromones on actual position. */
        if (!tile->pheromone_max()) {
            tile->setPheromones(tile->getPheromones() * Constants::Worker::PHEROMONE_INCREMENT);
        }
        /* Move to the previous position and continue while popping the
         * stack. */
        if (!stack.empty()) {
            this->position.goBack();
            this->pheromones_stock *= Constants::Worker::PHEROMONE_INCREMENT;
        } else {
            this->pheromones_stock = Constants::Worker::PHEROMONE_MAX;
            map->setColonyFood(map->getColonyFood() + 1);
            this->has_food = false;
        }
    } else {
        if (!minor_lifespan)
            this->major = true;

        if (!this->major) {
            basicMove(game);
            --minor_lifespan;
        } else {
            /* Look around and move where there is a lot of pheromones. */
            Tile **around        = game->getMap()->look_around(this->getPosition().getPos().x,
                                                               this->getPosition().getPos().y);
            Tile *targetted_tile = pheromone_around(around, map->getDimension() / 2);
            auto moving_to       = targetted_tile->getPos();

            delete around;

            if ((0 <= moving_to.x && moving_to.x < x_dimension && 0 <= moving_to.y
                 && moving_to.y < y_dimension)) {
                if (map->getTile(moving_to.x, moving_to.y)->isDiscovered()) {
                    this->position.setPos(moving_to);
                }
            }
        }
    }

    this->tryToEat(game);
}

Tile *Worker::pheromone_around(Tile **tiles_around, sf::Vector2i colony_pos)
{
    float phero_max   = 0.f;
    int   far_dist    = 0;
    int   phero_index = 0;
    int   far_index   = 0;


    for (int i = 0; i < 8; ++i) {
        if (tiles_around[i] != nullptr) {
            if ((*tiles_around[i]).getPheromones() >= phero_max) {
                phero_max   = (*tiles_around[i]).getPheromones();
                phero_index = i;
            }

            int x_dist = abs(colony_pos.x - tiles_around[i]->getPos().x);
            int y_dist = abs(colony_pos.y - tiles_around[i]->getPos().y);
            if (x_dist + y_dist + (rand() % Constants::Worker::MOVE_RANDOMNESS_LEVEL) > far_dist) {
                far_index = i;
                far_dist  = x_dist + y_dist;
            }
        }
    }

    if (phero_max > 0)
        return tiles_around[phero_index];
    else
        return tiles_around[far_index];
}


