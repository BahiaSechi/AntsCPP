//
// Created by kyojin on 23/11/2020.
//

#include <Board/ObstacleTile.h>

ObstacleTile::~ObstacleTile() {

}

ObstacleTile::ObstacleTile(const sf::Vector2i &position)
        : Tile(std::vector<Ant>(), position, tile_type::OBSTACLE)
{}
