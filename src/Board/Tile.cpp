//
// Created by kyojin on 23/11/2020.
//

#include <Board/Tile.h>

Tile::~Tile() {

}

Tile::Tile(std::vector<Ant> ants, const sf::Vector2i &position, tile_type
type) : ants (ants), pos(position), type(type)
{
}
