// Created by mateo on 25/11/2020.
//

#ifndef ANTS_EMPTYTILE_H
#define ANTS_EMPTYTILE_H

#include <Board/Tile.h>

class EmptyTile : public virtual Tile
{
public:
    EmptyTile(const sf::Vector2i &position);
};

#endif //ANTS_EMPTYTILE_H
