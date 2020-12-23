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
 * @file main.cpp
 * @version 1.0
 *
 * @brief Blabla
 */

#include <Game.h>

#include <iostream>

#include <Ants/Types/Queen.h>
#include <Graphics/TileDraw.h>
#include <Graphics/AntDraw.h>
#include <Graphics/GameRender.h>
#include <constants.h>

////////////////////////////////////////////////////////////
// Main methods
////////////////////////////////////////////////////////////

Game::Game(int width, int height)
        : map(new Map(height, width, 16, 2)), ants(std::vector<Ant *>()), renderer(new GameRender())
{
}

void Game::start(int turn_count = -1)
{
    onCreate();

    std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point t2 = std::chrono::system_clock::now();

    float elapsed_time = 0.0;
    loop_count = 0;

    renderer->startGraphics(this);
    sf::RenderWindow *window = &renderer->getWindow();

    while (window->isOpen() && (turn_count == -1 || --turn_count >= 0)) {
        sf::Event event{};
        while (window->pollEvent(event)) {
            handleLogicEvent(event, elapsed_time);
        }

        elapsed_time = wait(t1, t2);
        onLogicUpdate(elapsed_time);
        saveToFile();
    }
}

void Game::onCreate()
{
    map->generate();

    ants.push_back(new Queen(
            true,
            0.4,
            Position(Constants::Map::COLONY_POS, std::stack<sf::Vector2i>(), false)
    ));

    saveToFile();
}

void Game::onLogicUpdate(float elapsed_time)
{
    // Firstly, update data for every ant except the queen
    for (int i = 1; i < ants.size(); ++i)
        ants[i]->play_turn(this);

    // Then the queen has the opportunity to give birth
    ants[0]->play_turn(this);
}

void Game::handleLogicEvent(const sf::Event &event, float elapsed_time)
{
}

void Game::saveToFile()
{
    std::ofstream stat_file;
    stat_file.open("evolution.txt", std::ios::out | std::ios::app);

    if (loop_count < 0) {
        stat_file.open("evolution.txt", std::ios::out | std::ios::trunc);
        stat_file << "x acount cfood\n";
    } else {
        stat_file.open("evolution.txt", std::ios::out | std::ios::app);

        if (stat_file.is_open()) {
            stat_file << loop_count << ' ' << ants.size() << ' ' << std::to_string(map->getColonyFood()) << '\n';
        }
    }

    stat_file.close();
}

Game::~Game()
{
    for (Ant *ant : ants) {
        delete ant;
    }

    delete map;
    delete renderer;
}

////////////////////////////////////////////////////////////
// Non-member functions
////////////////////////////////////////////////////////////

float wait(std::chrono::system_clock::time_point &t1, std::chrono::system_clock::time_point &t2, float frametime)
{
    using namespace std::chrono;

    t1 = system_clock::now();
    duration<double, std::milli> work_time = t1 - t2;

    if (work_time.count() < frametime) {
        duration<double, std::milli> delta_ms(frametime - work_time.count());
        auto                         delta_ms_duration = duration_cast<milliseconds>(delta_ms);
        std::this_thread::sleep_for(milliseconds(delta_ms_duration.count()));
    }

    t2 = system_clock::now();
    duration<double, std::milli> sleep_time = t2 - t1;

    return work_time.count();
}

////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////

Map *Game::getMap() const
{
    return map;
}

void Game::setMap(Map &map)
{
    delete this->map;
    this->map = &map;
}

std::vector<Ant *> &Game::getAnts()
{
    return ants;
}

void Game::setAnts(const std::vector<Ant *> &ants)
{
    Game::ants = ants;
}

int Game::getLoopCount() const
{
    return loop_count;
}
