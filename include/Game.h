//
// Created by kyojin on 30/11/2020.
//

#ifndef ANTS_GAME_H
#define ANTS_GAME_H

#include <Board/Map.h>

class Game {
private:
    Map map;
    std::vector<Ant> ants;

public:
    void onCreate();
    void onUpdate();
};


#endif //ANTS_GAME_H
