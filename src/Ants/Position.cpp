//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Position.h>


Position::Position(const Tile &position, const std::stack<int> &pos_stack, bool register_post)
: position(position), pos_stack(pos_stack), register_post(register_post)
{
}

Position::~Position() {

}

const Tile &Position::getPosition() const
{
    return position;
}

void Position::setPosition(const Tile &pos)
{
    position = pos;
}
