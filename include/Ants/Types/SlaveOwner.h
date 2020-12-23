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

#ifndef ANTSPROJECT_SLAVEOWNER_H
#define ANTSPROJECT_SLAVEOWNER_H

#include <Ants/Types/Ant.h>
#include <Game.h>

class SlaveOwner : public virtual Ant {
private:
    bool has_larva;

public:
    SlaveOwner(bool has_larva, const Position &position);

    /**
     * For now, do some basic movements.
     *
     * @param game
     */
    void play_turn(Game *game) override;

    ~SlaveOwner() override;
};


#endif //ANTSPROJECT_SLAVEOWNER_H
