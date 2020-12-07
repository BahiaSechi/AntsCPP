//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/SlaveOwner.h>
#include <iostream>

SlaveOwner::SlaveOwner(bool has_larva, const Position &position) :
Ant(1, position,Alimentation(10, 0.1)) {}

SlaveOwner::~SlaveOwner() { }

void SlaveOwner::move(Game *game)
{
    std::cout << "I'm a slave owner" << std::endl;

}
