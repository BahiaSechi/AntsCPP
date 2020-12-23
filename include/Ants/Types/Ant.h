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
#include <Game.h>

class Game;
class Tile;

enum ant_type {
    QUEEN, WORKER, SCOUT, SLAVEOWNER, SOLDIER
};

class Ant {
protected:
    int lifespan;
    Position position;
    Alimentation alimentation;
    ant_type type;

public:
    Ant(int lifespan, const Position &position, const Alimentation &alimentation, ant_type type);
    virtual void play_turn(Game *game) = 0;
    virtual ~Ant();

    /**
     * Basic movements implementation.
     *
     * @param game
     * @param ignore_discovery Ignore the discovered state of tiles (for example : Scout)
     * @return
     */
    const sf::Vector2i &basicMove(Game *game, bool ignore_discovery = false);

    /**
     * Try to eat from the actual tile and return weither or not the ant is dead.
     *
     * @param game
     * @return
     */
    bool tryToEat(Game *game);

    int getLifespan() const;

    void setLifespan(int lifespan);

    const Position &getPosition() const;

    void setPosition(const Position &position);

    const Alimentation &getAlimentation() const;

    void setAlimentation(const Alimentation &alimentation);

    ant_type getType() const;
};


#endif //ANTSPROJECT_ANT_H
