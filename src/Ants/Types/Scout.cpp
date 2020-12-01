//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Scout.h>


Scout::Scout(bool major, int minorLifespan, const Position &position) :
Ant(1, position,Alimentation(0.1,1)) {}

Scout::~Scout() { }
