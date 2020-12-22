//
// Created by mateo on 09/12/2020.
//

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
