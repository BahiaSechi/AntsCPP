//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTSPROJECT_QUEEN_H
#define ANTSPROJECT_QUEEN_H

#include <Ants/Types/Ant.h>

class Queen : public Ant {
private:
    bool can_give_birth;

protected:
    int lifespan;
    float production_chance;

public:
    Queen(bool can_give_birth, int lifespan, float production_chance);
    ~Queen() override;

    void giveBirth() const;
};


#endif //ANTSPROJECT_QUEEN_H
