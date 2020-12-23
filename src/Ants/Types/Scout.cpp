//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Scout.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <constants.h>

Scout::Scout(bool major, int minorLifespan, const Position &position) :
        Ant(Constants::Ant::LIFESPAN, position, Alimentation(0.1, 1), SCOUT),
        minor_lifespan(minorLifespan), major(major)
{}

Scout::~Scout()
{}

void Scout::play_turn(Game *game)
{
    if (!major)
        --minor_lifespan;

    if (minor_lifespan <= 0)
        major = true;

    if (major) {
        basicMove(game, true);
        discoverTile(game, this->position.getPos().x, this->position.getPos().y);
    }
}

void Scout::discoverTile(Game *game, int pos_x, int pos_y)
{
    game->getMap()->getTile(pos_x, pos_y)->setDiscovered(true);
}
