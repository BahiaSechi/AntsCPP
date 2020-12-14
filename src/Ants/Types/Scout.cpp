//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Scout.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

Scout::Scout(bool major, int minorLifespan, const Position &position) :
        Ant(1, position, Alimentation(0.1, 1))
{}

Scout::~Scout()
{}

void Scout::play_turn(Game *game)
{
    if (this->major) {
        basicMove(game);
    }
}

void Scout::tileDiscovered(Game *game, int x_pos, int y_pos)
{
    game->getMap()->getTile(x_pos, y_pos)->setDiscovered(true);
}
