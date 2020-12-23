/**
 * Address :
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 * Note :
 * This file is owned by an ENSICAEN student.  No portion of this
 * document may be reproduced, copied  or revised without written
 * permission of the authors.
 *
 * @author Mateo RABOTIN <mateo.rabotin@ecole.ensicaen.fr>
 * @author Bahia SECHI <bahia.sechi@ecole.ensicaen.fr>
 *
 * @date November 2020
 * @file main.cpp
 * @version 1.0
 *
 * @brief Blabla
 */

#include <Board/Tile.h>

Tile::~Tile()
{

}

Tile::Tile(std::vector<Ant *> ants, const sf::Vector2i &position, tile_type type)
        : ants(ants), pos(position), type(type)
{
}

bool Tile::pheromone_max() {
    if (this->pheromones >= 1000) return true;
    else return false;
}


void Tile::evaporation() {
    this->pheromones *= 0.05;
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

