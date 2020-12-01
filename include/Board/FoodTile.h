//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTS_FOODTILE_H
#define ANTS_FOODTILE_H

#include <Board/Tile.h>

class FoodTile : public virtual Tile {
public:
    FoodTile(const sf::Vector2i &position);
    virtual ~FoodTile();
};


#endif //ANTS_FOODTILE_H
