//
// Created by mateo on 25/11/2020.
//

#include <Board/EmptyTile.h>

EmptyTile::EmptyTile(int antCount, const sf::Vector2i &position) : Tile(antCount, position, tile_type::EMPTY)
{
}
