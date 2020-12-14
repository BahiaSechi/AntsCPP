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
    std::stack<sf::Vector2i> pos_stack;
    bool register_post;

public:
    Position(const sf::Vector2i &pos, const std::stack<sf::Vector2i> &pos_stack,
             bool register_post);

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
