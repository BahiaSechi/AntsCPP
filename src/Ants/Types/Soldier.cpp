//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Soldier.h>
#include <algorithm>

Soldier::Soldier(int expedition_time, const Position &position) :
Ant(1, position, Alimentation(0.1,1)) {}

Soldier::~Soldier() {

}

void Soldier::attac(SlaveOwner &slave_owner) const { }

void Soldier::play_turn(Game *game)
{
    //TODO Verifier pas de fourmi esclavagiste sur la case
    auto whos_here = game->getMap()->getTiles()[this->position.getPos().x][this->position.getPos().y]->getAnts();
    const std::vector<Ant *>::iterator &is_slave_owner_here = std::find_if
            (whos_here.begin(), whos_here.end(),typeid(this) == typeid(SlaveOwner));

        //TODO Peut se deplacer si Tile decouverte


        //TODO Rajouter boolean tile decouverte


        //TODO A 100 jours, retour centre colonie
        if (expedition_time == 100) {
            //BLOU
        }
}

