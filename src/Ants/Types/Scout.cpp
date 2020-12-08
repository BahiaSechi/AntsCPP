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
    int x_pos = this->position.getPos().x;
    int y_pos = this->position.getPos().y;

    if (this->major) {

        switch (moving_chance) {
            case 1: // NO
                this->position.setPos({x_pos-1,y_pos-1});
                tileDiscovered(game, x_pos, y_pos);
                std::cout << "Nord ouest" << std::endl;
                break;
            case 2: // N
                this->position.setPos({x_pos,y_pos-1});
                tileDiscovered(game, x_pos, y_pos);
                std::cout << "Nord" << std::endl;
                break;
            case 3: // NE
                this->position.setPos({x_pos+1,y_pos-1});
                tileDiscovered(game, x_pos, y_pos);
                std::cout << "Nord est" << std::endl;
                break;
            case 4: // O
                this->position.setPos({x_pos-1,y_pos});
                tileDiscovered(game, x_pos, y_pos);
                std::cout << "Ouest" << std::endl;
                break;
            case 5: // E
                this->position.setPos({x_pos+1, y_pos});
                tileDiscovered(game, x_pos, y_pos);
                std::cout << "Est" << std::endl;
                break;
            case 6: // SO
                this->position.setPos({x_pos-1,y_pos+1});
                tileDiscovered(game, x_pos, y_pos);
                std::cout << "Sud ouest" << std::endl;
                break;
            case 7: // S
                this->position.setPos({x_pos,y_pos+1});
                tileDiscovered(game, x_pos, y_pos);
                std::cout << "Sud" << std::endl;
                break;
            case 8: // SE
                this->position.setPos({x_pos+1,y_pos+1});
                tileDiscovered(game, x_pos, y_pos);
                std::cout << "Sud est" << std::endl;
                break;
        }
    }
}

void Scout::tileDiscovered(Game *game, int x_pos, int y_pos)
{
    game->getMap()->getTiles()[x_pos][y_pos]->setDiscovered(true);
}
