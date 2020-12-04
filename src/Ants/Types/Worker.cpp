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

void Worker::play_turn(Game *game)
{
    /* Initialize random seed: */
    srand (time(NULL));
    int moving_chance = rand() % 8 + 1;

    /* Initialize variables. */
    int x_pos = this->position.getPos().x;
    int y_pos = this->position.getPos().y;

    //TODO Mettre dans une fonction la fonction de deplacement mineure et une
    // autre pour majeure
    if (!this->major) {
        switch (moving_chance) {
            case 1: // NO
                this->position.setPos({x_pos-1,y_pos-1});
                std::cout << "Nord ouest" << std::endl;
                break;
            case 2: // N
                this->position.setPos({x_pos,y_pos-1});
                std::cout << "Nord" << std::endl;
                break;
            case 3: // NE
                this->position.setPos({x_pos+1,y_pos-1});
                std::cout << "Nord est" << std::endl;
                break;
            case 4: // O
                this->position.setPos({x_pos-1,y_pos});
                std::cout << "Ouest" << std::endl;
                break;
            case 5: // E
                this->position.setPos({x_pos+1, y_pos});
                std::cout << "Est" << std::endl;
                break;
            case 6: // SO
                this->position.setPos({x_pos-1,y_pos+1});
                std::cout << "Sud ouest" << std::endl;
                break;
            case 7: // S
                this->position.setPos({x_pos,y_pos+1});
                std::cout << "Sud" << std::endl;
                break;
            case 8: // SE
                this->position.setPos({x_pos+1,y_pos+1});
                std::cout << "Sud est" << std::endl;
                break;
        }
    } else {
        /* Initialize variables. */
        sf::Vector2<int> ant_pos = this->position.getPos();
        std::stack<sf::Vector2i> &stack = this->position.getPosStack();

        auto map = game->getMap();
        auto tiles = map->getTiles();
        auto dimension = map->getDimension();

        /* Look around and move where there is a lot of pheromones. */
        Tile * around = this->look_around(game);
        this->position.setPos(pheromone_around(around).getPos());
        /* Push the position of the ant in the stack. */
        stack.push(ant_pos);

        //TODO Si plus de pheromones autour, on continue dans la même direction

        if (this->has_food) {
            /* Put pheromones on actual position. */
            tiles[x_pos][y_pos]->setPheromones(
                    tiles[x_pos][y_pos]->getPheromones()+1);
            /* Move to the previous position and continue while popping the
             * stack. */
            this->position.setPos(stack.top());
            stack.pop();
            this->pheromones_stock -= 1;
        }

        //TODO Changer centre de la colonie dans if.
        if (x_pos == dimension.x / 2 && y_pos == dimension.y / 2) {
            this->pheromones_stock = 500;
            map->setColonyFood(map->getColonyFood()+1);
            this->has_food = false;
        }
    }
}

Tile Worker::pheromone_around(Tile *tiles_around) {
    float max = 0.0;
    int index;
    for (int i = 0; i < 8; ++i) {
        if (tiles_around[i].getPheromones() >= max) {
            max = tiles_around[i].getPheromones();
            index = i;
        }
    }
    return tiles_around[index];
}


