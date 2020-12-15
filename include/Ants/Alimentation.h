//
// Created by kyojin on 23/11/2020.
//

#ifndef ANTS_ALIMENTATION_H
#define ANTS_ALIMENTATION_H



class Alimentation
{
private:
    float diet;
    int   diet_time;
    int   actual_diet_time;

public:
    Alimentation(float diet, int diet_time);

    ~Alimentation();

    /**
     * Set actual diet time to the base diet time.
     */
    void eat();

    /**
     * Reduce the actual diet time and return it.
     * If actual_diet_time is 0, the ant should die.
     *
     * @return actual_diet_time > 0
     */
    bool starve();

    float getDiet() const;

    void setDiet(float diet);

    int getDietTime() const;

    void setDietTime(int dietTime);

    int getActualDietTime() const;

    void setActualDietTime(int actualDietTime);
};


#endif //ANTS_ALIMENTATION_H
