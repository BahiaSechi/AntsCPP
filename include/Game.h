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

    /**
     * Called once when game starts.
     */
    void onCreate();

    /**
     * Called every frame to update logic.
     *
     * @param elapsed_time
     */
    void onLogicUpdate(float elapsed_time);

    /**
     * Handle logic related events (not for graphics).
     *
     * @param event
     * @param elapsed_time
     */
    void handleLogicEvent(const sf::Event &event, float elapsed_time);

    /**
     * Save game stats to evolution.txt.
     */
    void saveToFile();

    /**
     * Start the game (onCreate and onUpdate).
     *
     * @param turn_count
     */
    void start(int turn_count);

    Map *getMap() const;

    void setMap(Map &map);

    std::vector<Ant *> &getAnts();

    void setAnts(const std::vector<Ant *> &ants);

    int getLoopCount() const;

    virtual ~Game();
};

/**
 * Given t1 and t2, wait a specific time to comply with the time between frame (value set in the definition).
 *
 * @param t1
 * @param t2
 * @return the work time
 */
float wait(std::chrono::system_clock::time_point &t1, std::chrono::system_clock::time_point &t2, float frametime = 1000.0);


#endif //ANTS_GAME_H
