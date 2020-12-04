//
// Created by kyojin on 23/11/2020.
//

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
    Position::pos = pos;
}

std::stack<int> &Position::getPosStack() {
    return pos_stack;
}

void Position::setPosStack(const std::stack<int> &posStack) {
    pos_stack = posStack;
}
