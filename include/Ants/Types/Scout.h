//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTS_SCOUT_H
#define ANTS_SCOUT_H

#include <Ants/Types/Ant.h>
#include <Board/Map.h>
#include <Game.h>

class Scout : public virtual Ant {
private:
    bool major;
    int minor_lifespan;

public:
    Scout(bool major, int minorLifespan, const Position &position);

    void play_turn(Game game) override;

    ~Scout() override;
};


#endif //ANTS_SCOUT_H
