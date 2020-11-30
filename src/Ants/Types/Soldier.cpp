//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Soldier.h>

Soldier::Soldier(int expedition_time) :
Ant(1, position, Alimentation(0.1,1)) {}

Soldier::~Soldier() {

}

void Soldier::attack(SlaveOwner &slave_owner) const {

}
