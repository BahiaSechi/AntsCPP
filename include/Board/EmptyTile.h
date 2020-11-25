// Created by mateo on 25/11/2020.
//

#ifndef ANTS_EMPTYTILE_H
#define ANTS_EMPTYTILE_H

#include <Board/Tile.h>

class EmptyTile : public Tile
{
public:
    EmptyTile(int antCount, const sf::Vector2i &position);
};

#endif //ANTS_EMPTYTILE_H
