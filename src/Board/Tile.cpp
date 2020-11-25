//
// Created by kyojin on 23/11/2020.
//

#include <Board/Tile.h>

Tile::~Tile() {

}

Tile::Tile(int ant_count, const sf::Vector2i &position, tile_type type) : ant_count(ant_count), pos(position), type(type)
{
}

int Tile::getAntCount() const
{
    return ant_count;
}

void Tile::setAntCount(int antCount)
{
    ant_count = antCount;
}

const sf::Vector2i &Tile::getPos() const
{
    return pos;
}

void Tile::setPos(const sf::Vector2i &pos)
{
    Tile::pos = pos;
}

tile_type Tile::getType() const
{
    return type;
}

void Tile::setType(tile_type type)
{
    Tile::type = type;
}
