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
#include <Ants/Types/Scout.h>
#include <Ants/Types/Worker.h>
#include <Ants/Types/Soldier.h>

Queen::Queen(bool can_give_birth, int lifespan, float production_chance, const Position &position)
        : can_give_birth(can_give_birth), lifespan(lifespan), production_chance(production_chance),
          Ant(10, position, Alimentation(1, 1))
{
}

Queen::~Queen()
{}

Ant *Queen::giveBirth(bool enforce_scout = false) const
{
    if (enforce_scout) {
        return new Scout(
                false,
                2,
                Position(this->position.getPos(), std::stack<int>(), false)
        );
    }

    float birth_proba = rand() % 100 + 1;

    if (birth_proba <= 80) {
        Position pos = Position(this->position.getPos(), std::stack<int>(), true);
        return new Worker(false, false, 500, 15, pos);
    } else if (birth_proba <= 95) {
        Position pos = Position(this->position.getPos(), std::stack<int>(), false);
        return new Soldier(100, pos);
    } else {
        Position pos = Position(this->position.getPos(), std::stack<int>(), false);
        return new Scout(false, 2, pos);
    }
}

void Queen::move(Game *game)
{
    if (can_give_birth) {
        for (int i : {1, 2}) {
            game->getAnts().push_back(giveBirth(game->getAnts().empty()));
        }
    }
}


