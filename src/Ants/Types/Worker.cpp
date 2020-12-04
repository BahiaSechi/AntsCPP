//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Worker.h>

Worker::Worker(bool has_food, bool major, int pheromones_stock,int minor_lifespan, const Position &position) :
Ant(1, position, Alimentation(0.1,1)) {}

Worker::~Worker() {

}

void Worker::move(Game *game)
{

}
