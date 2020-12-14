//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Soldier.h>
#include <algorithm>
#include <iostream>

Soldier::Soldier(int expedition_time, const Position &position) :
        Ant(1, position, Alimentation(0.1, 1))
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
    auto tiles       = map->getTiles();

    // Verify is there is no slave owner on the tile.
    auto whos_here = tiles[y_pos][x_pos]->getAnts();

    auto is_slave_owner_here =
            std::find_if(whos_here.begin(), whos_here.end(), [whos_here](Ant *ant) {
                return typeid(*ant) == typeid(SlaveOwner);
            });

    if (is_slave_owner_here != whos_here.end()) {
        rasenshuriken_no_jutsu(*is_slave_owner_here);
    }

    if (expedition_time != 100) {
        basicMove(game);
    } else {
        // Go back to the colony.
        if (tiles[y_pos][x_pos]->getType() != tile_type::COLONY) {
            this->position.goBack();
        } else {
            stack.empty();
        }
    }
}

