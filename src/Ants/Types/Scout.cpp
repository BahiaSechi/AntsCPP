//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Scout.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

Scout::Scout(bool major, int minorLifespan, const Position &position) :
        Ant(1, position, Alimentation(0.1, 1))
{}

Scout::~Scout()
{}

void Scout::play_turn(Game *game)
{
    /* Initialize random seed: */
    srand(time(NULL));
    int moving_chance = rand() % 8 + 1;

    /* Initialize variables. */
    sf::Vector2<int> ant_pos = this->position.getPos();
    int x_pos = ant_pos.x;
    int y_pos = ant_pos.y;
    auto map = game->getMap();
    int x_dimension = map->getDimension().x;
    int y_dimension = map->getDimension().y;
    int future_x, future_y;

    if (this->major) {

        switch (moving_chance) {
            case 1: // NO
                future_x = x_pos-1;
                future_y = y_pos-1;
                std::cout << "Nord ouest" << std::endl;
                break;
            case 2: // N
                future_x = x_pos;
                future_y = y_pos-1;
                std::cout << "Nord" << std::endl;
                break;
            case 3: // NE
                future_x = x_pos+1;
                future_y = y_pos-1;
                std::cout << "Nord est" << std::endl;
                break;
            case 4: // O
                future_x = x_pos-1;
                future_y = y_pos;
                std::cout << "Ouest" << std::endl;
                break;
            case 5: // E
                future_x = x_pos+1;
                future_y = y_pos;
                std::cout << "Est" << std::endl;
                break;
            case 6: // SO
                future_x = x_pos-1;
                future_y = y_pos+1;
                std::cout << "Sud ouest" << std::endl;
                break;
            case 7: // S
                future_x = x_pos;
                future_y = y_pos+1;
                std::cout << "Sud" << std::endl;
                break;
            case 8: // SE
                future_x = x_pos+1;
                future_y = y_pos+1;
                std::cout << "Sud est" << std::endl;
                break;
        }
        if (0 <= future_x && future_x < x_dimension && 0 <= future_y && future_y < y_dimension) {
            this->position.setPos({future_y, future_x});
            tileDiscovered(game, future_y, future_x);
        }
    }
}

void Scout::tileDiscovered(Game *game, int x_pos, int y_pos)
{
    game->getMap()->getTiles()[y_pos][x_pos]->setDiscovered(true);
}
