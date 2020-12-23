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

#ifndef ANTSPROJECT_SOLDIER_H
#define ANTSPROJECT_SOLDIER_H

#include <Ants/Types/Ant.h>
#include <Ants/Types/SlaveOwner.h>

class Soldier : public virtual Ant {
private:
    int expedition_time;

public:
    Soldier(int expedition_time, const Position &position);
    ~Soldier() override;

    /**
     * While the soldier is minor, does not do much. Then, when major, go find and attack slave owners.
     *
     * @param game
     */
    void play_turn(Game *game) override;

    /**
     * Attack a slave owner.
     *
     * @param slave_owner
     */
    void rasenshuriken_no_jutsu(Ant *slave_owner) const;
};

#endif //ANTSPROJECT_SOLDIER_H
