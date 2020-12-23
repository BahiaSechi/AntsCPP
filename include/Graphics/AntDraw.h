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

#ifndef ANTS_ANTDRAW_H
#define ANTS_ANTDRAW_H

#include <SFML/Graphics/Texture.hpp>

class AntDraw
{
public:
    std::pair<sf::Vector2i, sf::Vector2i> queen_texture;
    std::pair<sf::Vector2i, sf::Vector2i> scout_texture;
    std::pair<sf::Vector2i, sf::Vector2i> slaveowner_texture;
    std::pair<sf::Vector2i, sf::Vector2i> soldier_texture;
    std::pair<sf::Vector2i, sf::Vector2i> worker_texture;

    sf::Texture ants_texture;

    AntDraw();
};

#endif //ANTS_ANTDRAW_H
