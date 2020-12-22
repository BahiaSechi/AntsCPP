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
 * @file Ant.cpp
 * @version 1.0
 *
 * @brief Blabla
 */

#include <Ants/Types/Ant.h>
#include <random>


Ant::Ant(int lifespan, const Position &position, const Alimentation &alimentation, ant_type type) :
        lifespan(lifespan), alimentation(alimentation), position(position), type(type)
{}

Ant::~Ant()
{}

const sf::Vector2i &Ant::basicMove(Game *game, bool ignore_discovery)
{
    std::random_device               rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937                     gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(1, 8);

    auto ant_pos       = this->position.getPos();
    int  x_pos         = ant_pos.x;
    int  y_pos         = ant_pos.y;
    int  moving_chance = dis(gen);
    int  future_x, future_y;
    auto map           = game->getMap();
    int  x_dimension   = map->getDimension().x;
    int  y_dimension   = map->getDimension().y;


    switch (moving_chance) {
        case 1: // NO
            future_x = x_pos - 1;
            future_y = y_pos - 1;
//            std::cout << "Nord ouest" << std::endl;
            break;
        case 2: // N
            future_x = x_pos;
            future_y = y_pos - 1;
//            std::cout << "Nord" << std::endl;
            break;
        case 3: // NE
            future_x = x_pos + 1;
            future_y = y_pos - 1;
//            std::cout << "Nord est" << std::endl;
            break;
        case 4: // O
            future_x = x_pos - 1;
            future_y = y_pos;
//            std::cout << "Ouest" << std::endl;
            break;
        case 5: // E
            future_x = x_pos + 1;
            future_y = y_pos;
//            std::cout << "Est" << std::endl;
            break;
        case 6: // SO
            future_x = x_pos - 1;
            future_y = y_pos + 1;
//            std::cout << "Sud ouest" << std::endl;
            break;
        case 7: // S
            future_x = x_pos;
            future_y = y_pos + 1;
//            std::cout << "Sud" << std::endl;
            break;
        case 8: // SE
            future_x = x_pos + 1;
            future_y = y_pos + 1;
//            std::cout << "Sud est" << std::endl;
            break;
    }

    if ((0 <= future_x && future_x < x_dimension && 0 <= future_y && future_y < y_dimension)
        && (map->getTile(future_x, future_y)->isDiscovered() || ignore_discovery)
        ) {
        this->position.setPos({future_x, future_y});
    }

    return this->position.getPos();
}

bool Ant::tryToEat(Game *game)
{
    const sf::Vector2i &pos = this->position.getPos();
    if (game->getMap()->reduceFood(pos.x, pos.y, this->alimentation.getDiet())) {
        this->alimentation.eat();

        return true;
    }


    return this->alimentation.starve();
}

int Ant::getLifespan() const
{
    return lifespan;
}

void Ant::setLifespan(int lifespan)
{
    Ant::lifespan = lifespan;
}

const Position &Ant::getPosition() const
{
    return position;
}

void Ant::setPosition(const Position &position)
{
    Ant::position = position;
}

const Alimentation &Ant::getAlimentation() const
{
    return alimentation;
}

void Ant::setAlimentation(const Alimentation &alimentation)
{
    Ant::alimentation = alimentation;
}

ant_type Ant::getType() const
{
    return type;
}
