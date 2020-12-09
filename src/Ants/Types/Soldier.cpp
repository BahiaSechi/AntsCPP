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
    int x_pos = this->position.getPos().x;
    int y_pos = this->position.getPos().y;
    sf::Vector2<int> ant_pos = this->position.getPos();
    std::stack<sf::Vector2i> stack = this->position.getPosStack();
    auto map = game->getMap();
    auto tiles = map->getTiles();

    //TODO Verifier pas de fourmi esclavagiste sur la case
    auto whos_here = game->getMap()->getTiles()[x_pos][y_pos]->getAnts();

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
        //TODO Retour a la colonie
        if (tiles[x_pos][y_pos]->getType() != tile_type::COLONY) {
            this->position.setPos(stack.top());
            stack.pop();
        } else {
            stack.empty();
        }
    }
}

