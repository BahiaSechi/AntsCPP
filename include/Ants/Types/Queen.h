/**
 * Address :
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 * Note :
 * This file is owned by an ENSICAEN student.  No portion of this
 * document may be reproduced, copied  or revised without written
 * permission of the authors.
 *
 * @author Mateo RABOTIN <mateo.rabotin@ecole.ensicaen.fr>
 * @author Bahia SECHI <bahia.sechi@ecole.ensicaen.fr>
 *
 * @date November 2020
 * @file main.cpp
 * @version 1.0
 *
 * @brief Blabla
 */

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

    /**
     * The queen try to guve birth to two ants each turn. She does not move.
     *
     * @param game
     */
    void play_turn(Game *game) override;

    ~Queen() override;

    /**
     * Birth type chance : Worker 80%, Soldier 15%, Scout 5%.
     *
     * @param enforce_scout
     * @return A new Ant of one of the three types above
     */
    Ant *giveBirth(bool enforce_scout) const;
};


#endif //ANTSPROJECT_QUEEN_H
