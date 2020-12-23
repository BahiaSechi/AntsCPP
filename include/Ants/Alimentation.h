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
