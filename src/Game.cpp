//
// Created by kyojin on 30/11/2020.
//

#include <Game.h>
#include <Ants/Types/Queen.h>
#include <iostream>
#include <fstream>

Game::Game(int width, int height)
        : map(height, width, 16, 2), ants(std::vector<Ant *>())
{
}

void Game::onCreate()
{
    Queen *queen = new Queen(true, 100, 0.4, Position({0, 0}, std::stack<int>(), false));
    ants.push_back(queen);

    std::cout << getMap() << std::endl;
}

void Game::updateGraphics() const
{
    // TODO: Voir ça plus tard
}

void Game::onUpdate(float elapsed_time)
{
    std::cout << elapsed_time << std::endl;
    // TODO: Handle events

    // TODO: Update data
    for (Ant *ant : ants)
        ant->move();

    // TODO: Update graphics
    // graphic_thread.join();
}

void Game::saveToFile(const std::string &filename = "evolution.txt") const
{
    std::ofstream stat_file;
    stat_file.open(filename, std::ios::out | std::ios::trunc);

    if (stat_file.is_open()) {
        stat_file << ants.size() << '\n';
        stat_file << map.getColonyFood() << '\n';
    }
}

void Game::start()
{
    using namespace std;
    using namespace std::chrono;

    onCreate();

    system_clock::time_point a = system_clock::now();
    system_clock::time_point b = system_clock::now();

    float time_between_frame = 1000.0;

    while (true) {

        a = system_clock::now();
        duration<double, std::milli> work_time = a - b;

        if (work_time.count() < time_between_frame)
        {
            duration<double, std::milli> delta_ms(time_between_frame - work_time.count());
            auto delta_ms_duration = duration_cast<milliseconds>(delta_ms);
            std::this_thread::sleep_for(milliseconds(delta_ms_duration.count()));
        }

        b = system_clock::now();
        duration<double, std::milli> sleep_time = b - a;

        onUpdate(work_time.count());
        saveToFile();
    }
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