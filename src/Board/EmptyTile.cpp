//
// Created by mateo on 25/11/2020.
//

#include <Board/EmptyTile.h>

EmptyTile::EmptyTile(sf::Vector2<*Ant> ants, const sf::Vector2i &position) :
Tile (ants, position, tile_type::EMPTY)
{
}
