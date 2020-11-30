//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTS_POSITION_H
#define ANTS_POSITION_H

#include <stack>

#include <SFML/System/Vector2.hpp>

#include <Board/Tile.h>

class Tile;

class Position {
protected:
    Tile position;
    std::stack<int> pos_stack;
    bool register_post;

public:
    Position(const Tile &position, const std::stack<int> &pos_stack, bool register_post);
    ~Position();

    // Getters & setters
    const Tile &getPosition() const;
    void setPosition(const Tile &pos);
};


#endif //ANTS_POSITION_H
