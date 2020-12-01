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
 * @file Queen.cpp
 * @version 1.0
 *
 * @brief Blabla
 */

#include <Ants/Types/Queen.h>
#include <iostream>
#include <Game.h>

Queen::Queen(bool can_give_birth, int lifespan, float production_chance, const Position &position)
        : can_give_birth(can_give_birth), lifespan(lifespan), production_chance(production_chance),
          Ant(10, position, Alimentation(1, 1))
{
}

Queen::~Queen() { }

void Queen::giveBirth() const {

}

void Queen::move(Game *game)
{
    // The queen does not move.
}


