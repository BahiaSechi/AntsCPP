//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Soldier.h>
#include <algorithm>
#include <iostream>

Soldier::Soldier(int expedition_time, const Position &position) :
Ant(1, position, Alimentation(0.1,1)) {}

Soldier::~Soldier() {

}

void Soldier::attac(SlaveOwner &slave_owner) const { }

void Soldier::play_turn(Game *game) {

    /* Initialize variables. */
    sf::Vector2<int> ant_pos = this->position.getPos();
    int x_pos = ant_pos.x;
    int y_pos = ant_pos.y;
    std::stack<sf::Vector2i> stack = this->position.getPosStack();
    auto map = game->getMap();
    auto tiles = map->getTiles();
    int x_dimension = map->getDimension().x;
    int y_dimension = map->getDimension().y;
    int future_x, future_y;

    //TODO Verifier pas de fourmi esclavagiste sur la case
    auto whos_here = tiles[x_pos][y_pos]->getAnts();

    const std::vector<Ant *>::iterator &is_slave_owner_here =
            std::find_if(whos_here.begin(), whos_here.end(),[whos_here](Ant * ant) {
                return typeid(*ant) == typeid(SlaveOwner);
            });

    if (is_slave_owner_here != whos_here.end()) {
        //TODO ATTACK
    }

    if (expedition_time != 100) {
        /* Initialize random seed: */
        srand(time(NULL));
        int moving_chance = rand() % 8 + 1;

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
        && tiles[future_x][future_y]->isDiscovered()){
            this->position.setPos({future_x, future_y});
            stack.push(ant_pos);
        }
    } else {
        //TODO Retour a la colonie
        if (tiles[x_pos][y_pos]->getType() != tile_type::COLONY) {
            this->position.setPos(stack.top());
            stack.pop();
        } else {
            stack.empty();
        }
    }
}

