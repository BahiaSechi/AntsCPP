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

#ifndef ANTS_SCOUT_H
#define ANTS_SCOUT_H

#include <Ants/Types/Ant.h>

class Scout : public virtual Ant {
private:
    bool major;
    int minor_lifespan;

public:
    Scout(bool major, int minorLifespan, const Position &position);

    /**
     * While minor, stay in the colony. When major, go discover tiles.
     * @param game
     */
    void play_turn(Game *game) override;

    ~Scout() override;

    void discoverTile(Game *game, int pos_x, int pos_y);
};


#endif //ANTS_SCOUT_H
