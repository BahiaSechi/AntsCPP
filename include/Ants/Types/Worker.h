//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTSPROJECT_WORKER_H
#define ANTSPROJECT_WORKER_H

#include <Ants/Types/Ant.h>

class Worker : public virtual Ant {
private:
    bool has_food;
    bool major;
    float pheromones_stock;
    int minor_lifespan;

public:
    Worker(bool has_food, bool major, int pheromones_stock, int minor_lifespan, const Position &position);

    void play_turn(Game game) override;

    ~Worker();
};


#endif //ANTSPROJECT_WORKER_H
