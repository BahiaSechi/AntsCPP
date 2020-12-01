//
// Created by kyojin on 30/11/2020.
//

#include <Game.h>
#include <Ants/Types/Queen.h>
#include <iostream>

void Game::onCreate()
{
    Queen queen = Queen(true, 100, 0.4, Position({0, 0}, std::stack<int>(), false));
    ants.push_back(&queen);

    std::cout << getMap() << std::endl;
}

void Game::updateGraphics()
{
    // TODO: Voir ça plus tard
}

void Game::onUpdate()
{
    // TODO: Gérer les events

    // TODO: Mettre à jour les données
    for (Ant *ant : ants)
        (*ant).move();

    // TODO: mettre à jour l'affichage
//    graphic_thread.join();

}

[[noreturn]] Game::Game(int width, int height)
        : map(height, width, 16, 2), ants(std::vector<Ant *>())
{
    onCreate();

    while (true)
        onUpdate();
}

// Getters and setters

const Map &Game::getMap() const
{
    return map;
}

void Game::setMap(const Map &map)
{
    Game::map = map;
}

const std::vector<Ant *> &Game::getAnts() const
{
    return ants;
}

void Game::setAnts(const std::vector<Ant *> &ants)
{
    Game::ants = ants;
}
