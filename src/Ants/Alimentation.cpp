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
 * @file Alimentation.cpp
 * @version 1.0
 *
 * @brief Blabla
 */

#include <Ants/Alimentation.h>

Alimentation::Alimentation(float diet, int diet_time)
:diet(diet), diet_time(diet_time), actual_diet_time(diet_time)
{
}

Alimentation::~Alimentation() {

}

void Alimentation::eat()
{
    actual_diet_time = diet_time;
}

bool Alimentation::starve()
{
    --actual_diet_time;
    return actual_diet_time > 0;
}

float Alimentation::getDiet() const
{
    return diet;
}

void Alimentation::setDiet(float diet)
{
    Alimentation::diet = diet;
}

int Alimentation::getDietTime() const
{
    return diet_time;
}

void Alimentation::setDietTime(int dietTime)
{
    diet_time = dietTime;
}

int Alimentation::getActualDietTime() const
{
    return actual_diet_time;
}

void Alimentation::setActualDietTime(int actualDietTime)
{
    actual_diet_time = actualDietTime;
}
