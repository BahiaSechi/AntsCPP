//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTSPROJECT_SOLDIER_H
#define ANTSPROJECT_SOLDIER_H

#include <Ants/Types/Ant.h>
#include <Ants/Types/SlaveOwner.h>

class Soldier : public Ant {
private:
    int expedition_time;

public:
    void attack(SlaveOwner &slave_wner) const;
};

#endif //ANTSPROJECT_SOLDIER_H
