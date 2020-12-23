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

#ifndef ANTS_POSITION_H
#define ANTS_POSITION_H

#include <stack>

#include <SFML/System/Vector2.hpp>

class Position {
protected:
    sf::Vector2i pos;
    std::stack<sf::Vector2i> pos_stack;
    bool register_post;

public:
    Position(const sf::Vector2i &pos, const std::stack<sf::Vector2i> &pos_stack,
             bool register_post);

    /**
     * Take the top of the stack and move the ant back to this pos.
     * @return
     */
    const sf::Vector2i &goBack();

    // Getters & setters
    const sf::Vector2i &getPos() const;

    void setPos(const sf::Vector2i &pos);

    const std::stack<sf::Vector2i> &getPosStack() const;

    void setPosStack(const std::stack<sf::Vector2i> &posStack);

    bool isRegisterPost() const;

    void setRegisterPost(bool registerPost);
};


#endif //ANTS_POSITION_H
