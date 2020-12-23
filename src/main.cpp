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

#include <iostream>
#include <Game.h>
#include <constants.h>

#ifndef ANTS_TEST
int main()
{
    Game game(Constants::Map::DIMENSION.x, Constants::Map::DIMENSION.y);
    game.start(-1);

    return 0;
}
#endif