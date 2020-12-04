//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Soldier.h>
#include <iostream>

Soldier::Soldier(int expedition_time, const Position &position) :
Ant(1, position, Alimentation(0.1,1)) {}

Soldier::~Soldier() {

}

void Soldier::attack(SlaveOwner &slave_owner) const {

}

void Soldier::move(Game *game)
{
    std::cout << "I'm a soldier" << std::endl;

}
