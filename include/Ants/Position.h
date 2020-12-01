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
    Position(const sf::Vector2i &pos, const std::stack<int> &pos_stack, bool register_post);

    // Getters & setters
    const sf::Vector2i &getPos() const;

    void setPos(const sf::Vector2i &pos);
};


#endif //ANTS_POSITION_H
