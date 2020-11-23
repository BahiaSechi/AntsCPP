//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTS_ALIMENTATION_H
#define ANTS_ALIMENTATION_H


class Alimentation {
private:
    int diet;
    int diet_time;

public:
    void eat();
    Alimentation(int diet, int diet_time);
};


#endif //ANTS_ALIMENTATION_H
