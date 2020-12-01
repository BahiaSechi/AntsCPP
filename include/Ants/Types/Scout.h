//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTS_SCOUT_H
#define ANTS_SCOUT_H

#include <Ants/Types/Ant.h>

class Scout : public virtual Ant {
private:
    bool major;
    int minor_lifespan;

public:
    Scout(bool major, int minorLifespan, const Position &position);
    ~Scout() override;
};


#endif //ANTS_SCOUT_H
