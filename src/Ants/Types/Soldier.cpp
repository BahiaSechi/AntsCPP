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

#include <Ants/Types/Soldier.h>
#include <algorithm>
#include <iostream>
#include <constants.h>

Soldier::Soldier(int expedition_time, const Position &position) :
        Ant(Constants::Ant::LIFESPAN, position, Alimentation(0.1, 1), SOLDIER)
{}

Soldier::~Soldier()
{

}

/*
 * Soldier can attack one slave owner in the tile.
 */
void Soldier::rasenshuriken_no_jutsu(Ant *slave_owner) const
{
    delete &slave_owner;
}

void Soldier::play_turn(Game *game)
{

    /* Initialize variables. */
    auto ant_pos     = this->position.getPos();
    int  x_pos       = ant_pos.x;
    int  y_pos       = ant_pos.y;
    auto stack       = this->position.getPosStack();
    auto map         = game->getMap();

    // Verify if there is no slave owner on tile.
    auto whos_here = map->getTile(x_pos, y_pos)->getAnts();

    auto is_slave_owner_here =
            std::find_if(whos_here.begin(), whos_here.end(), [whos_here](Ant *ant) {
                return typeid(*ant) == typeid(SlaveOwner);
            });

    // If there is one or several slave owners, kill one.
    if (is_slave_owner_here != whos_here.end()) {
        rasenshuriken_no_jutsu(*is_slave_owner_here);
    }

    if (expedition_time != Constants::Soldier::MAX_EXPEDITION_TIME) {
        basicMove(game);
    } else {
        // Go back to the colony.
        if (map->getTile(x_pos, y_pos)->getType() != tile_type::COLONY) {
            this->position.goBack();
        } else {
            stack.empty();
        }
    }
}

