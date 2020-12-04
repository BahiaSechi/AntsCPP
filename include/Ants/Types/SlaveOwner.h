//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTSPROJECT_SLAVEOWNER_H
#define ANTSPROJECT_SLAVEOWNER_H

#include <Ants/Types/Ant.h>
#include <Game.h>

class SlaveOwner : public virtual Ant {
private:
    bool has_larva;

public:
    SlaveOwner(bool has_larva, const Position &position);

    void play_turn(Game *game) override;

    ~SlaveOwner() override;
};


#endif //ANTSPROJECT_SLAVEOWNER_H
