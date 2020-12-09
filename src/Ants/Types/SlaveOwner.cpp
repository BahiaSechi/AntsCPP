//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/SlaveOwner.h>
#include <iostream>
#include <Game.h>

SlaveOwner::SlaveOwner(bool has_larva, const Position &position) :
Ant(1, position,Alimentation(10, 0.1)) {}

SlaveOwner::~SlaveOwner() { }

void SlaveOwner::play_turn(Game *game) {
    /* Initialize random seed: */
    srand(time(NULL));
    int moving_chance = rand() % 8 + 1;

    /* Initialize variables. */
    int x_pos = this->position.getPos().x;
    int y_pos = this->position.getPos().y;
    auto map = game->getMap();
    int x_dimension = map->getDimension().x;
    int y_dimension = map->getDimension().y;
    int future_x, future_y;

    switch (moving_chance) {
        case 1: // NO
            future_x = x_pos - 1;
            future_y = y_pos - 1;
            std::cout << "Nord ouest" << std::endl;
            break;
        case 2: // N
            future_x = x_pos;
            future_y = y_pos - 1;
            std::cout << "Nord" << std::endl;
            break;
        case 3: // NE
            future_x = x_pos + 1;
            future_y = y_pos - 1;
            std::cout << "Nord est" << std::endl;
            break;
        case 4: // O
            future_x = x_pos - 1;
            future_y = y_pos;
            std::cout << "Ouest" << std::endl;
            break;
        case 5: // E
            future_x = x_pos + 1;
            future_y = y_pos;
            std::cout << "Est" << std::endl;
            break;
        case 6: // SO
            future_x = x_pos - 1;
            future_y = y_pos + 1;
            std::cout << "Sud ouest" << std::endl;
            break;
        case 7: // S
            future_x = x_pos;
            future_y = y_pos + 1;
            std::cout << "Sud" << std::endl;
            break;
        case 8: // SE
            future_x = x_pos + 1;
            future_y = y_pos + 1;
            std::cout << "Sud est" << std::endl;
            break;
    }
    if (0 <= future_x && future_x < x_dimension && 0 <= future_y && future_y < y_dimension) {
        this->position.setPos({future_x, future_y});
    }
}
