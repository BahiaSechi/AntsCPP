//
// Created by kyojin on 23/11/2020.
//

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
