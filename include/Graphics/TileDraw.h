//
// Created by mateo on 09/12/2020.
//

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
