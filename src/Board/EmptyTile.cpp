//
// Created by mateo on 25/11/2020.
//

#include <Board/EmptyTile.h>

EmptyTile::EmptyTile(const sf::Vector2i &position)
        : Tile(std::vector<Ant *>(), position, tile_type::EMPTY)
{}
