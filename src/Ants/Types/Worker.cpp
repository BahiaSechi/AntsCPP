//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Worker.h>
#include <ctime>
#include <iostream>

Worker::Worker(bool has_food, bool major, int pheromones_stock,int minor_lifespan, const Position &position) :
Ant(1, position, Alimentation(0.1,1)) {}

Worker::~Worker() {

}

void Worker::play_turn(Game game)
{
    /* Initialize random seed: */
    srand (time(NULL));
    int moving_chance = rand() % 8 + 1;

    if (!this->major) {

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
                    this->position.getPos().x+1, this->position.getPos().y
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
    } else {

        //TODO Regarder autour puis se deplacer selon les pheromones
        //TODO Aller dans le sens des pheromones sans s'arreter jusqu'a
        // trouver de la nourriture

        if (this->has_food) {
            //TODO Se diriger vers le centre de la colonie
            this->pheromones_stock -= 0.002;
        }
/**
        //TODO Changer centre de la colonie dans if.
        if (this->position.getPos().x == game.getDimension().x / 2 &&
            this->position.getPos().y == game.getDimension().y / 2)
        {
            this->pheromones_stock = 500;
            game.setColonyFood(game.getColonyFood() + 1);
            this->has_food = false;
        }
        */
    }
}
