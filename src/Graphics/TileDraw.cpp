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

#include <Graphics/TileDraw.h>

TileDraw::TileDraw()
{
    tile_texture.loadFromFile("assets/world/Overworld.png");

    colony_texture = {536, 57};
    empty_discovered_texture = {192,208};
    empty_texture = {0, 0};
    food_discovered_texture = {1, 546};
    food_texture = {15, 544};
    obstacle_texture = {480, 3};
}
