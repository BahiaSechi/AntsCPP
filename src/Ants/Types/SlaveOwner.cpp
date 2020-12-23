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

#include <Ants/Types/SlaveOwner.h>
#include <iostream>
#include <Game.h>

SlaveOwner::SlaveOwner(bool has_larva, const Position &position) :
        Ant(10, position, Alimentation(10, 0.1), SLAVEOWNER)
{}

SlaveOwner::~SlaveOwner() { }

void SlaveOwner::play_turn(Game *game) {
    basicMove(game);
}
