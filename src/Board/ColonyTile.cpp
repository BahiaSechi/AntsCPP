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
 * @file ColonyTile.cpp
 * @version 1.0
 *
 * @brief Blabla
 */

#include <Board/ColonyTile.h>

ColonyTile::ColonyTile(std::vector<Ant> ants, const sf::Vector2i &position1,
                       tile_type type, int antCount,
                       const sf::Vector2i &position) : Tile(ants, position, type) {}
