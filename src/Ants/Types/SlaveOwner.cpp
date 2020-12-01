//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/SlaveOwner.h>
#include <Board/Map.h>

SlaveOwner::SlaveOwner(bool has_larva, const Position &position) :
Ant(1, position,Alimentation(10, 0.1)) {}

SlaveOwner::~SlaveOwner() { }

void SlaveOwner::move(Map map)
{

}
