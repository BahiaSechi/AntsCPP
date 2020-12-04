//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/SlaveOwner.h>
#include <Board/Map.h>
#include <iostream>
#include <Game.h>

SlaveOwner::SlaveOwner(bool has_larva, const Position &position) :
Ant(1, position,Alimentation(10, 0.1)) {}

SlaveOwner::~SlaveOwner() { }

void SlaveOwner::play_turn(Game game)
{
    /* Initialize random seed: */
    srand (time(NULL));
    int moving_chance = rand() % 8 + 1;

    switch (moving_chance) {
        case 1: // NO
            this->position.setPos({
                                          this->position.getPos().x-1,this->position.getPos().y-1
                                  });
            std::cout << "Nord ouest" << std::endl;
            break;
        case 2: // N
            this->position.setPos({
                                          this->position.getPos().x,this->position.getPos().y-1
                                  });
            std::cout << "Nord" << std::endl;
            break;
        case 3: // NE
            this->position.setPos({
                                          this->position.getPos().x+1,this->position.getPos().y-1
                                  });
            std::cout << "Nord est" << std::endl;
            break;
        case 4: // O
            this->position.setPos({
                                          this->position.getPos().x-1,this->position.getPos().y
                                  });
            std::cout << "Ouest" << std::endl;
            break;
        case 5: // E
            this->position.setPos({
                                          this->position.getPos().x+1,this->position.getPos().y
                                  });
            std::cout << "Est" << std::endl;
            break;
        case 6: // SO
            this->position.setPos({
                                          this->position.getPos().x-1,this->position.getPos().y+1
                                  });
            std::cout << "Sud ouest" << std::endl;
            break;
        case 7: // S
            this->position.setPos({
                                          this->position.getPos().x,this->position.getPos().y+1
                                  });
            std::cout << "Sud" << std::endl;
            break;
        case 8: // SE
            this->position.setPos({
                                          this->position.getPos().x+1,this->position.getPos().y+1
                                  });
            std::cout << "Sud est" << std::endl;
            break;
    }
}
