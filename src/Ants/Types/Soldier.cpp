//
// Created by kyojin on 23/11/2020.
//

#include <Ants/Types/Soldier.h>

Soldier::Soldier(int expedition_time, const Position &position) :
Ant(1, position, Alimentation(0.1,1)) {}

Soldier::~Soldier() {

}

void Soldier::attack(SlaveOwner &slave_owner) const {

}

void Soldier::play_turn(Game *game)
{
    //TODO Verifier pas de fourmi esclavagiste avant de bouger
    //TODO Peut se deplacer si Tile decouverte
    //TODO Rajouter boolean tile decouverte
    //TODO A 100 jours, retour centre colonie
    if (expedition_time == 100) {
        //BLOU
    }
}
