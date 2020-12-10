//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Worker.h>
#include <ctime>
#include <iostream>

Worker::Worker(bool has_food, bool major, int pheromones_stock,int minor_lifespan, const Position &position) :
Ant(1, position, Alimentation(0.1,1)) {}

Worker::~Worker() { }

void Worker::play_turn(Game *game) {
    /* Initialize random seed: */
    srand(time(NULL));
    int moving_chance = rand() % 8 + 1;

    /* Initialize variables. */
    int x_pos = this->position.getPos().x;
    int y_pos = this->position.getPos().y;
    sf::Vector2<int> ant_pos = this->position.getPos();
    std::stack<sf::Vector2i> stack = this->position.getPosStack();
    auto map = game->getMap();
    auto tiles = map->getTiles();
    int x_dimension = map->getDimension().x;
    int y_dimension = map->getDimension().y;
    int future_x, future_y;

    //TODO Mettre dans une fonction la fonction de deplacement mineure et une
    // autre pour majeure
    if (!this->major) {
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
        if ((0 <= future_x && future_x < x_dimension && 0 <= future_y && future_y < y_dimension)
            && tiles[future_x][future_y]->isDiscovered()) {
            this->position.setPos({future_x, future_y});
            stack.push(ant_pos);
        }
    } else {

        /* Look around and move where there is a lot of pheromones. */
        Tile *around = this->look_around(game);
        auto moving_to = pheromone_around(around).getPos();

        if ((0 <= moving_to.x && moving_to.x < x_dimension && 0 <= moving_to.y
        && moving_to.y < y_dimension)) {
            if (tiles[moving_to.x][moving_to.y]->isDiscovered()) {
                this->position.setPos(moving_to);
                stack.push(ant_pos);
            }
        }
    }

    //TODO Si plus de pheromones autour, on continue dans la même direction

    if (this->has_food) {
        /* Put pheromones on actual position. */
        tiles[x_pos][y_pos]->setPheromones(
                tiles[x_pos][y_pos]->getPheromones() * 0.08);
        /* Move to the previous position and continue while popping the
         * stack. */
        if (!stack.empty()) {
            this->position.setPos(stack.top());
            stack.pop();
            this->pheromones_stock *= 0.08;
        } else {
            this->pheromones_stock = 500;
            map->setColonyFood(map->getColonyFood() + 1);
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


