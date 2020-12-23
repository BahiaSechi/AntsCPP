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

#include <Ants/Position.h>


Position::Position(const sf::Vector2i &pos, const std::stack<sf::Vector2i>
        &pos_stack, bool register_post)
: pos(pos), pos_stack(pos_stack), register_post(register_post)
{
}

const sf::Vector2i &Position::getPos() const
{
    return pos;
}

void Position::setPos(const sf::Vector2i &pos)
{
    if (this->register_post) {
        pos_stack.push(this->pos);
    }

    Position::pos = pos;
}

const std::stack<sf::Vector2i> &Position::getPosStack() const
{
    return pos_stack;
}

void Position::setPosStack(const std::stack<sf::Vector2i> &posStack)
{
    pos_stack = posStack;
}

bool Position::isRegisterPost() const
{
    return register_post;
}

void Position::setRegisterPost(bool registerPost)
{
    register_post = registerPost;
}

const sf::Vector2i &Position::goBack()
{
    pos = pos_stack.top();
    pos_stack.pop();

    return pos;
}
