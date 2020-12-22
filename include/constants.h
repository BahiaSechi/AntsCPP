//
// Created by mateo on 22/12/2020.
//

#ifndef ANTS_CONSTANTS_H
#define ANTS_CONSTANTS_H

namespace Constants
{
    namespace Ant
    {
        const int LIFESPAN = 10;
    }

    namespace Scout
    {
        const int MINOR_LIFESPAN = 2;
    }

    namespace Soldier
    {
        const int MAX_EXPEDITION_TIME = 100;
    }

    namespace Queen
    {
        const int LIFESPAN = 100;
    }

    namespace Worker
    {
        const int MINOR_LIFESPAN = 15;

        const int MOVE_RANDOMNESS_LEVEL = 5;

        const float PHEROMONE_INCREMENT = 0.08;
        const int   PHEROMONE_MAX       = 500;
    }
}


#endif //ANTS_CONSTANTS_H
