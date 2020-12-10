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
 * @file Ant.cpp
 * @version 1.0
 *
 * @brief Blabla
 */

#include <Ants/Types/Ant.h>


Ant::Ant(int lifespan, const Position &position, const Alimentation &alimentation):
lifespan(lifespan), alimentation(alimentation), position(position){}

Ant::~Ant() {}

Tile *Ant::look_around(Game *game) {

    int x_pos = this->position.getPos().x;
    int y_pos = this->position.getPos().y;

    auto tiles = *(game->getMap()->getTiles());

    Tile around[8] = {
            tiles[x_pos-1][y_pos-1],
            tiles[x_pos][y_pos-1],
            tiles[x_pos+1][y_pos-1],
            tiles[x_pos-1][y_pos],
            tiles[x_pos+1][y_pos],
            tiles[x_pos-1][y_pos+1],
            tiles[x_pos][y_pos+1],
            tiles[x_pos+1][y_pos+1],
    };

    return around;
}

int Ant::getLifespan() const
{
    return lifespan;
}

void Ant::setLifespan(int lifespan)
{
    Ant::lifespan = lifespan;
}

const Position &Ant::getPosition() const
{
    return position;
}

void Ant::setPosition(const Position &position)
{
    Ant::position = position;
}

const Alimentation &Ant::getAlimentation() const
{
    return alimentation;
}

void Ant::setAlimentation(const Alimentation &alimentation)
{
    Ant::alimentation = alimentation;
}

//void Ant::move() {
//
//    /* Initialize random seed: */
//    srand (time(NULL));
//    int moving_chance = rand() % 8 + 1;
//
//    switch (moving_chance) {
//        case 1:
//        this->position.getTile().get
//            break;
//        case 2: // N
//            this->position.setPos(this->position.getPos().x,
//                                  this->position.getPos().y-1);
//            break;
//        case 3: // NE
//            this->position.setPos(this->position.getPos().x+1,
//                                  this->position.getPos().y-1);
//            break;
//        case 4: // O
//            this->position.setPos(this->position.getPos().x-1,
//                                  this->position.getPos().y);
//            break;
//        case 5: // E
//            this->position.setPos(this->position.getPos().x+1,
//                                  this->position.getPos().y);
//            break;
//        case 6: // SO
//            this->position.setPos(this->position.getPos().x-1,
//                                  this->position.getPos().y+1);
//            break;
//        case 7: // S
//            this->position.setPos(this->position.getPos().x,
//                                  this->position.getPos().y+1);
//            break;
//        case 8: // SE
//            this->position.setPos(this->position.getPos().x+1,
//                                  this->position.getPos().y+1);
//            break;
//    }
//
//    // Toute fourmi possede une memoire de son chemin est du centre de la colonie
//
//}

