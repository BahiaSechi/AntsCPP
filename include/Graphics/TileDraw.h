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

#ifndef ANTS_TILEDRAW_H
#define ANTS_TILEDRAW_H

#include <SFML/Graphics/Texture.hpp>

class TileDraw
{
public:
    sf::Vector2i colony_texture;
    sf::Vector2i empty_discovered_texture;
    sf::Vector2i empty_texture;
    sf::Vector2i food_discovered_texture;
    sf::Vector2i food_texture;
    sf::Vector2i obstacle_texture;

    sf::Texture tile_texture;

    TileDraw();
};

#endif //ANTS_TILEDRAW_H
