//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTS_OBSTACLETILE_H
#define ANTS_OBSTACLETILE_H

#include <Board/Tile.h>

class ObstacleTile : public Tile {
public:
    ObstacleTile(int antCount, const sf::Vector2i &position);
    virtual ~ObstacleTile();
};


#endif //ANTS_OBSTACLETILE_H
