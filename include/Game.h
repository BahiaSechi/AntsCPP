//
// Created by kyojin on 30/11/2020.
//

#ifndef ANTS_GAME_H
#define ANTS_GAME_H

#include <atomic>
#include <fstream>
#include <thread>

#include <Ants/Types/Ant.h>
#include <Board/Map.h>
#include <Board/Tile.h>

#include <SFML/Graphics.hpp>
#include <Graphics/GameRender.h>

class Ant;
class GameRender;
class Map;
class Tile;

class Game
{
private:
    Map                *map;
    std::vector<Ant *> ants;
    GameRender         *renderer;
    int loop_count;

public:
    Game(int width, int height);

    void onCreate();

    void onLogicUpdate(float elapsed_time);

    void handleLogicEvent(const sf::Event &event, float elapsed_time);

    void saveToFile();

    void start(int turn_count);

    Map *getMap() const;

    void setMap(Map &map);

    std::vector<Ant *> &getAnts();

    void setAnts(const std::vector<Ant *> &ants);

    int getLoopCount() const;

    virtual ~Game();
};

/**
 * Given t1 and t2, wait a specific time to comply with the time between frame (value set in the definition)
 *
 * @param t1
 * @param t2
 * @return the work time
 */
float wait(std::chrono::system_clock::time_point &t1, std::chrono::system_clock::time_point &t2, float frametime = 1000.0);


#endif //ANTS_GAME_H
