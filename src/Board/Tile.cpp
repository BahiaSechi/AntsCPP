//
// Created by kyojin on 23/11/2020.
//

#include <Board/Tile.h>

Tile::~Tile() {

}

Tile::Tile(sf::Vector2<*Ant> ants, const sf::Vector2i &position, tile_type
type) : ants (ants), pos(position), type(type)
{
}

const sf::Vector2<*Ant> &Tile::getAnts() const {
    return ants;
}

void Tile::setAnts(const sf::Vector2<*Ant> &ants) {
    Tile::ants = ants;
}

tile_type Tile::getType() const {
    return type;
}

void Tile::setType(tile_type type) {
    Tile::type = type;
}
