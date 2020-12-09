//
// Created by kyojin on 30/11/2020.
//

#ifndef ANTS_GAME_H
#define ANTS_GAME_H

#include <atomic>
#include <fstream>

#include <Ants/Types/Ant.h>
#include <Board/Map.h>

#include <SFML/Graphics.hpp>

class Ant;

class Map;

class Game
{
private:
    Map *map;

    std::vector<Ant *> ants;

    sf::RenderWindow window;

    std::atomic<sf::Vector2f> view_center = std::atomic<sf::Vector2f>(sf::Vector2f(0.0f, 0.0f));
    std::atomic<sf::Vector2f> view_size   = std::atomic<sf::Vector2f>(sf::Vector2f(500.0f, 500.0f));
    std::atomic<float>        view_zoom   = std::atomic<float>({1.0f});

    int tile_size = 16;

public:
    Game(int width, int height);

    void onCreate();

    void onLogicUpdate(float elapsed_time);

    void handleEvent(const sf::Event &event, float elapsed_time);

    void saveToFile(int loop_count);

    void start(int turn_count);

    Map *getMap() const;

    void setMap(Map &map);

    std::vector<Ant *> &getAnts();

    void setAnts(const std::vector<Ant *> &ants);

    virtual ~Game();

    const std::atomic<sf::Vector2f> &getViewCenter() const;

    void setViewCenter(const sf::Vector2f &viewCenter);

    const std::atomic<sf::Vector2f> &getViewSize() const;

    void setViewSize(const sf::Vector2f &viewSize);

    const std::atomic<float> &getViewZoom() const;

    void setViewZoom(float viewZoom);

    int getTileSize() const;

    void setTileSize(int tileSize);
};

/**
 * Function called by a delegated thread to update graphics
 *
 * @param window
 */
void updateGraphics(sf::RenderWindow &window, Game *game);

/**
 * Given t1 and t2, wait a specific time to comply with the time between frame (value set in the definition)
 *
 * @param t1
 * @param t2
 * @return the work time
 */
float wait(std::chrono::system_clock::time_point t1, std::chrono::system_clock::time_point t2);


#endif //ANTS_GAME_H
