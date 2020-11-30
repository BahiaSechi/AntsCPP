/**
 * Address :
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 * Note :
 * This file is owned by an ENSICAEN student.  No portion of this
 * document may be reproduced, copied  or revised without written
 * permission of the authors.
 *
 * @author Mateo RABOTIN <mateo.rabotin@ecole.ensicaen.fr>
 * @author Bahia SECHI <bahia.sechi@ecole.ensicaen.fr>
 *
 * @date November 2020
 * @file Ant.cpp
 * @version 1.0
 *
 * @brief Blabla
 */

#include <Ants/Types/Ant.h>
#include <ctime>
#include <cstdlib>

Ant::Ant(int lifespan, const Position &position, const Alimentation &alimentation):
lifespan(lifespan), alimentation(alimentation), position(position){}

Ant::~Ant() {}

void Ant::move() {

    /* Initialize random seed: */
    srand (time(NULL));
    int moving_chance = rand() % 8 + 1;

    /*switch (moving_chance) {
        case 1:
        this->position.getPosition().get
            break;
        case 2: // N
            this->position.setPos(this->position.getPos().x,
                                  this->position.getPos().y-1);
            break;
        case 3: // NE
            this->position.setPos(this->position.getPos().x+1,
                                  this->position.getPos().y-1);
            break;
        case 4: // O
            this->position.setPos(this->position.getPos().x-1,
                                  this->position.getPos().y);
            break;
        case 5: // E
            this->position.setPos(this->position.getPos().x+1,
                                  this->position.getPos().y);
            break;
        case 6: // SO
            this->position.setPos(this->position.getPos().x-1,
                                  this->position.getPos().y+1);
            break;
        case 7: // S
            this->position.setPos(this->position.getPos().x,
                                  this->position.getPos().y+1);
            break;
        case 8: // SE
            this->position.setPos(this->position.getPos().x+1,
                                  this->position.getPos().y+1);
            break;
    }*/


    // Toute fourmi possede une memoire de son chemin est du centre de la colonie

    //SOLDAT
    // Verifier pas de fourmi esclavagiste
    // Peut se deplacer en zone connue
    //Si ca fait cent jours, il veut repasser par le centre de la colonie

    //OUVRIERE
    // Si majeure, déplacement lié aux pheromon
    // Chercher la nourriture dans une direction donnee (has_food = true)
    // Se dirige dans une case en fonction de la dose de pheromone
    // Prendre la nourriture et faire demi tour vers le centre puis deposer
    // Dans chaque case dans laquelle elle passe au retour, depot pheromone
    // Centre de la colonie : has_food = false ; pheromones = 500

}

