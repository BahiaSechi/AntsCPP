//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTSPROJECT_QUEEN_H
#define ANTSPROJECT_QUEEN_H

#include <Ants/Types/Ant.h>
#include <Game.h>

class Queen : public virtual Ant
{
private:
    bool  can_give_birth;
    float production_chance;

public:
    Queen(bool can_give_birth, float production_chance, const Position &position);

    void play_turn(Game *game) override;

    ~Queen() override;

    /**
     * Birth type chance : Worker 80%, Soldier 15%, Scout 5%
     *
     * @param enforce_scout
     * @return A new Ant of one of the three types above
     */
    Ant *giveBirth(bool enforce_scout) const;
};


#endif //ANTSPROJECT_QUEEN_H
