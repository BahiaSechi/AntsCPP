//
// Created by kyojin on 30/11/2020.
//

#ifndef ANTS_GAME_H
#define ANTS_GAME_H

#include <Board/Map.h>
#include <Ants/Types/Ant.h>
#include <thread>
#include <fstream>

class Game
{
private:
    Map map;
    std::vector<Ant *> ants;
//    std::thread graphic_thread;

public:
    Game(int width, int height);

    void updateGraphics() const;

    void onCreate();

    void onUpdate(float elapsed_time);

    void saveToFile(int loop_count);

    [[noreturn]] void start();

    const Map &getMap() const;

    void setMap(const Map &map);

    const std::vector<Ant *> &getAnts() const;

    void setAnts(const std::vector<Ant *> &ants);

    virtual ~Game();
};


#endif //ANTS_GAME_H
