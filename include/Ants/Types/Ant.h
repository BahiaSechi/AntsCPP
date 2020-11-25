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
 * @file Ant.h
 * @version 1.0
 *
 * @brief Blabla
 */

#ifndef ANTSPROJECT_ANT_H
#define ANTSPROJECT_ANT_H

#include <Ants/Alimentation.h>
#include <Ants/Position.h>

class Ant {
protected:
    int lifespan;
    Position position;
    Alimentation alimentation;

public:
    Ant(int lifespan, const Position &position,
        const Alimentation &alimentation);
    void move();
    virtual ~Ant();

};


#endif //ANTSPROJECT_ANT_H
