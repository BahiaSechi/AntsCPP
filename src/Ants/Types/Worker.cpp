//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Worker.h>
#include <ctime>
#include <iostream>

Worker::Worker(bool has_food, bool major, int pheromones_stock,int minor_lifespan, const Position &position) :
Ant(1, position, Alimentation(0.1,1)) {}

Worker::~Worker() { }

void Worker::play_turn(Game *game)
{
    /* Initialize random seed: */
    srand (time(NULL));
    int moving_chance = rand() % 8 + 1;

    /* Initialize variables. */
    int x_pos = this->position.getPos().x;
    int y_pos = this->position.getPos().y;
    sf::Vector2<int> ant_pos = this->position.getPos();
    std::stack<sf::Vector2i> stack = this->position.getPosStack();
    auto map = game->getMap();
    auto tiles = map->getTiles();


    //TODO Mettre dans une fonction la fonction de deplacement mineure et une
    // autre pour majeure
    if (!this->major) {
        switch (moving_chance) {
            case 1: // NO
                if (tiles[x_pos - 1][y_pos-1]->isDiscovered()) {
                    this->position.setPos({x_pos - 1, y_pos - 1});
                    stack.push(ant_pos);
                    std::cout << "Nord ouest" << std::endl;
                }
                break;
            case 2: // N
                if (tiles[x_pos][y_pos-1]->isDiscovered()) {
                    this->position.setPos({x_pos, y_pos - 1});
                    stack.push(ant_pos);
                    std::cout << "Nord" << std::endl;
                }
                break;
            case 3: // NE
                if (tiles[x_pos + 1][y_pos - 1]->isDiscovered()) {
                    this->position.setPos({x_pos + 1, y_pos - 1});
                    stack.push(ant_pos);
                    std::cout << "Nord est" << std::endl;
                }
                break;
            case 4: // O
                if (tiles[x_pos - 1][y_pos]->isDiscovered()) {
                    this->position.setPos({x_pos - 1, y_pos});
                    stack.push(ant_pos);
                    std::cout << "Ouest" << std::endl;
                }
                break;
            case 5: // E
                if (tiles[x_pos + 1][y_pos]->isDiscovered()) {
                    this->position.setPos({x_pos + 1, y_pos});
                    stack.push(ant_pos);
                    std::cout << "Est" << std::endl;
                }
                break;
            case 6: // SO
                if (tiles[x_pos - 1][y_pos + 1]->isDiscovered())
                    this->position.setPos({x_pos - 1, y_pos + 1});
                stack.push(ant_pos);
                std::cout << "Sud ouest" << std::endl;
                break;
            case 7: // S
                if (tiles[x_pos][y_pos + 1]->isDiscovered()) {
                    this->position.setPos({x_pos, y_pos + 1});
                    stack.push(ant_pos);
                    std::cout << "Sud" << std::endl;
                }
                break;
            case 8: // SE
                if (tiles[x_pos + 1][y_pos + 1]->isDiscovered())
                    this->position.setPos({x_pos + 1, y_pos + 1});
                stack.push(ant_pos);
                std::cout << "Sud est" << std::endl;
                break;
        }
    } else {

        /* Look around and move where there is a lot of pheromones. */
        Tile * around = this->look_around(game);
        auto moving_to = pheromone_around(around).getPos();
        if (tiles[moving_to.x][moving_to.y]->isDiscovered()) {
            this->position.setPos(moving_to);
            /* Push the position of the ant in the stack. */
            stack.push(ant_pos);
        }

        //TODO Si plus de pheromones autour, on continue dans la même direction

        if (this->has_food) {
            /* Put pheromones on actual position. */
            tiles[x_pos][y_pos]->setPheromones(
                    tiles[x_pos][y_pos]->getPheromones()+1);
            /* Move to the previous position and continue while popping the
             * stack. */
            if (!stack.empty()) {
                this->position.setPos(stack.top());
                stack.pop();
                this->pheromones_stock -= 1;
            } else {
                this->pheromones_stock = 500;
                map->setColonyFood(map->getColonyFood()+1);
                this->has_food = false;
            }
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


