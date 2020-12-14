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
