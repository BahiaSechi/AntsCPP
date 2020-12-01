//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTS_ALIMENTATION_H
#define ANTS_ALIMENTATION_H


class Alimentation {
private:
    float diet;
    int diet_time;

public:
    Alimentation(int diet, int diet_time);
    ~Alimentation();
    void eat();
};


#endif //ANTS_ALIMENTATION_H
