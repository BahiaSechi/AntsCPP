//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Worker.h>

Worker::Worker(bool has_food, bool major, int pheromones_stock, int minor_lifespan, const Position &position) :
        Ant(1, position, Alimentation(0.1, 1))
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
    Tile * tile = map->getTile(x_pos, y_pos);

    if (!this->major) {
        basicMove(game);
    } else {
        /* Look around and move where there is a lot of pheromones. */
        Tile **around   = game->getMap()->look_around(this->getPosition().getPos().x,
                                                      this->getPosition().getPos().y);
        auto moving_to = pheromone_around(around).getPos();

        if ((0 <= moving_to.x && moving_to.x < x_dimension && 0 <= moving_to.y
             && moving_to.y < y_dimension)) {
            if (map->getTile(moving_to.x, moving_to.y)->isDiscovered()) {
                this->position.setPos(moving_to);
            }
        }
    }

    //TODO Si plus de pheromones autour, on continue dans la même direction

    if (this->has_food) {
        /* Put pheromones on actual position. */
        if (!tile->pheromone_max()) {
            tile->setPheromones(tile->getPheromones() * 0.08);
        }
        /* Move to the previous position and continue while popping the
         * stack. */
        if (!stack.empty()) {
            this->position.goBack();
            this->pheromones_stock *= 0.08;
        } else {
            this->pheromones_stock = 500;
            map->setColonyFood(map->getColonyFood() + 1);
            this->has_food = false;
        }
    }
}

Tile Worker::pheromone_around(Tile **tiles_around)
{
    float    max = 0.0;
    int      index;
    for (int i   = 0; i < 8; ++i) {
        if ((*tiles_around[i]).getPheromones() >= max) {
            max   = (*tiles_around[i]).getPheromones();
            index = i;
        }
    }
    return *tiles_around[index];
}


