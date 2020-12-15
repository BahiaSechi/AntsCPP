//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTS_COLONYTILE_H
#define ANTS_COLONYTILE_H

#include <Board/Tile.h>

class ColonyTile : public virtual Tile
{
public:
    ColonyTile(const sf::Vector2i &position);

    virtual ~ColonyTile();
};

#endif //ANTS_COLONYTILE_H
