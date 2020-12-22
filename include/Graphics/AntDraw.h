//
// Created by mateo on 09/12/2020.
//

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
