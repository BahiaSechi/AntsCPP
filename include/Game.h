//
// Created by kyojin on 30/11/2020.
//

#ifndef ANTS_GAME_H
#define ANTS_GAME_H

#include <thread>
#include <fstream>

#include <Ants/Types/Ant.h>
#include <Board/Map.h>

class Ant;
class Map;

class Game
{
private:
    Map *map;
    std::vector<Ant *> ants;

public:
    Game(int width, int height);

    void updateGraphics() const;

    void onCreate();

    void onUpdate(float elapsed_time);

    void saveToFile(int loop_count);

    void start(int turn_count);

    const Map * getMap() const;

    void setMap(Map &map);

    std::vector<Ant *> &getAnts();

    void setAnts(const std::vector<Ant *> &ants);

    virtual ~Game();
};


#endif //ANTS_GAME_H
