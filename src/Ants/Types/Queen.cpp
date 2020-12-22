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
 * YAS QUEEN YAAAS
 *
 * @brief Blabla
 *
 */

#include <Ants/Types/Queen.h>
#include <iostream>
#include <Game.h>
#include <Ants/Types/Scout.h>
#include <Ants/Types/Worker.h>
#include <Ants/Types/Soldier.h>
#include <constants.h>

Queen::Queen(bool can_give_birth, float production_chance, const Position &position)
        : can_give_birth(can_give_birth), production_chance(production_chance),
          Ant(Constants::Queen::LIFESPAN, position, Alimentation(1, 1), QUEEN)
{}

Queen::~Queen()
{}

Ant *Queen::giveBirth(bool enforce_scout = false) const
{
    if (enforce_scout) {
        return new Scout(
                false,
                2,
                Position(this->position.getPos(), std::stack<sf::Vector2i>(), false)
        );
    }

    float birth_proba = rand() % 100 + 1;

    if (birth_proba <= 80) {
        Position pos = Position(this->position.getPos(), std::stack<sf::Vector2i>(), true);
        return new Worker(false, false, Constants::Worker::PHEROMONE_MAX, Constants::Worker::MINOR_LIFESPAN, pos);
    } else if (birth_proba <= 95) {
        Position pos = Position(this->position.getPos(), std::stack<sf::Vector2i>(), false);
        return new Soldier(Constants::Soldier::MAX_EXPEDITION_TIME, pos);
    } else {
        Position pos = Position(this->position.getPos(), std::stack<sf::Vector2i>(), false);
        return new Scout(false, Constants::Scout::MINOR_LIFESPAN, pos);
    }
}

void Queen::play_turn(Game *game)
{
    if (can_give_birth) {
        for (int i : {1, 2}) {
            game->getAnts().push_back(giveBirth(game->getAnts().empty()));
        }
    }
}


