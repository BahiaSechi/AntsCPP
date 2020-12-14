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

void Soldier::attac(SlaveOwner &slave_owner) const
{}

void Soldier::play_turn(Game *game)
{

    /* Initialize variables. */
    auto ant_pos     = this->position.getPos();
    int  x_pos       = ant_pos.x;
    int  y_pos       = ant_pos.y;
    auto stack       = this->position.getPosStack();
    auto map         = game->getMap();
    auto tiles       = map->getTiles();
    int  x_dimension = map->getDimension().x;
    int  y_dimension = map->getDimension().y;
    int  future_x, future_y;

    //TODO Verifier pas de fourmi esclavagiste sur la case
    auto whos_here = tiles[y_pos][x_pos]->getAnts();

    const std::vector<Ant *>::iterator &is_slave_owner_here =
                                               std::find_if(whos_here.begin(), whos_here.end(), [whos_here](Ant *ant) {
                                                   return typeid(*ant) == typeid(SlaveOwner);
                                               });

    if (is_slave_owner_here != whos_here.end()) {
        //TODO ATTACK
    }

    if (expedition_time != 100) {
        basicMove(game);
    } else {
        //TODO Retour a la colonie
        if (tiles[y_pos][x_pos]->getType() != tile_type::COLONY) {
            this->position.goBack();
        } else {
            stack.empty();
        }
    }
}

