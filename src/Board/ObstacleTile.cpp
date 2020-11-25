//
// Created by kyojin on 23/11/2020.
//

#include <Board/ObstacleTile.h>

ObstacleTile::ObstacleTile(sf::Vector2<*Ant> ants, const sf::Vector2i
&position) : Tile (ants, position, tile_type::OBSTACLE)
{}

ObstacleTile::~ObstacleTile() {

}