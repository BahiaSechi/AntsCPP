//
// Created by kyojin on 30/11/2020.
//

#ifndef ANTS_GAME_H
#define ANTS_GAME_H

#include <thread>
#include <fstream>

#include <Ants/Types/Ant.h>
#include <Board/Map.h>

#include <SFML/Graphics.hpp>

class Ant;

class Map;

class Game
{
private:
    Map                *map;
    std::vector<Ant *> ants;

public:
    Game(int width, int height);

    void onCreate();

    void onLogicUpdate(float elapsed_time);

    void saveToFile(int loop_count);

    void start(int turn_count);

    Map * getMap() const;

    void setMap(Map &map);

    std::vector<Ant *> &getAnts();

    void setAnts(const std::vector<Ant *> &ants);

    virtual ~Game();
};

/**
 * Function called by a delegated thread to update graphics
 *
 * @param window
 */
void updateGraphics(sf::RenderWindow &window);

/**
 * Given t1 and t2, wait a specific time to comply with the time between frame (value set in the definition)
 *
 * @param t1
 * @param t2
 * @return the work time
 */
float wait(std::chrono::system_clock::time_point t1, std::chrono::system_clock::time_point t2);


#endif //ANTS_GAME_H
