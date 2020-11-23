//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTS_POSITION_H
#define ANTS_POSITION_H

#include <stack>

#include <SFML/System/Vector2.hpp>

class Position {
protected:
    sf::Vector2i pos;
    std::stack<int> pos_stack;
    bool register_post;

public:
    void move();
};


#endif //ANTS_POSITION_H
