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

#ifndef ANTS_FOODTILE_H
#define ANTS_FOODTILE_H

#include <Board/Tile.h>

class FoodTile : public virtual Tile
{
private:
    int  food_stock;
    bool big_source;

public:
    FoodTile(const sf::Vector2i &position, bool big);

    virtual ~FoodTile();

    int getFoodStock() const;

    void setFoodStock(int foodStock);

    bool isBigSource() const;

    void setBigSource(bool bigSource);
};


#endif //ANTS_FOODTILE_H
