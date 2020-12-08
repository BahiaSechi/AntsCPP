//
// Created by kyojin on 23/11/2020.
//

#include <Board/Tile.h>

Tile::~Tile()
{

}

Tile::Tile(std::vector<Ant *> ants, const sf::Vector2i &position, tile_type type)
        : ants(ants), pos(position), type(type)
{
}

tile_type Tile::getType() const
{
    return type;
}

const std::vector<Ant *> &Tile::getAnts() const
{
    return ants;
}

void Tile::setAnts(const std::vector<Ant *> &ants)
{
    this->ants = ants;
}

const sf::Vector2i &Tile::getPos() const
{
    return pos;
}

float Tile::getPheromones() const {
    return pheromones;
}

void Tile::setPheromones(float pheromones) {
    this->pheromones = pheromones;
}

bool Tile::isDiscovered() const {
    return discovered;
}

void Tile::setDiscovered(bool discovered) {
    this->discovered = discovered;
}
