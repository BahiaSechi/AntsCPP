//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTS_COLONYTILE_H
#define ANTS_COLONYTILE_H

#include <Board/Tile.h>

class ColonyTile : public Tile {
public:
    ColonyTile(int antCount, const sf::Vector2i &position);
};

#endif //ANTS_COLONYTILE_H
