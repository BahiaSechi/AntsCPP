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
 * @file FoodTile.cpp
 * @version 1.0
 *
 * @brief Blabla
 */

#include <Board/FoodTile.h>

FoodTile::FoodTile(const sf::Vector2i &position, bool big = false)
        : Tile(std::vector<Ant *>(), position, tile_type::FOOD), big_source(big), food_stock(big ? 100000:10)
{}

int FoodTile::getFoodStock() const
{
    return food_stock;
}

void FoodTile::setFoodStock(int foodStock)
{
    food_stock = foodStock;
}

bool FoodTile::isBigSource() const
{
    return big_source;
}

void FoodTile::setBigSource(bool bigSource)
{
    big_source = bigSource;
}

FoodTile::~FoodTile()
{

}
