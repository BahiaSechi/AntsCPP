//
// Created by kyojin on 23/11/2020.
//

#include <Board/ObstacleTile.h>

ObstacleTile::ObstacleTile(int antCount, const sf::Vector2i &position) : Tile(antCount, position, tile_type::OBSTACLE)
{}

ObstacleTile::~ObstacleTile() {

}