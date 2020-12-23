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

#ifndef ANTS_EMPTYTILE_H
#define ANTS_EMPTYTILE_H

#include <Board/Tile.h>

class EmptyTile : public virtual Tile
{
public:
    EmptyTile(const sf::Vector2i &position);

    ~EmptyTile() override;
};

#endif //ANTS_EMPTYTILE_H
