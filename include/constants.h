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

#ifndef ANTS_CONSTANTS_H
#define ANTS_CONSTANTS_H

namespace Constants
{
    namespace Ant
    {
        const int LIFESPAN = 10;
    }

    namespace Map
    {
        const sf::Vector2i COLONY_POS = {105, 100};
        const sf::Vector2i DIMENSION = {211, 201};

        const float TILESIZE = 16;
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
