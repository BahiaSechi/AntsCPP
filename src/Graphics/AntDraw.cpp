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

#include <Graphics/AntDraw.h>

#include <utility>

AntDraw::AntDraw()
{
    ants_texture.loadFromFile("assets/ants/walk_naruto.png");

    queen_texture      = std::make_pair<sf::Vector2i, sf::Vector2i>({400, 0}, {600, 250});
    scout_texture      = std::make_pair<sf::Vector2i, sf::Vector2i>({200, 0}, {400, 250});
    slaveowner_texture = std::make_pair<sf::Vector2i, sf::Vector2i>({0, 0}, {200, 250});
    soldier_texture    = std::make_pair<sf::Vector2i, sf::Vector2i>({600, 0}, {800, 250});
    worker_texture     = std::make_pair<sf::Vector2i, sf::Vector2i>({800, 0}, {1000, 250});
}
