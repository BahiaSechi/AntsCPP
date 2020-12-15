//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/SlaveOwner.h>
#include <iostream>
#include <Game.h>

SlaveOwner::SlaveOwner(bool has_larva, const Position &position) :
Ant(10, position,Alimentation(10, 0.1)) {}

SlaveOwner::~SlaveOwner() { }

void SlaveOwner::play_turn(Game *game) {
    basicMove(game);
}
