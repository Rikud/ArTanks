#include "bot.h"

Bot::Bot(Tank *val) : Player (val)
{
    size = HEAD_SIZE * MAX_ARN + 1;
}

void Bot::genGeneration()
{
    for(i = 0; i < POPULATION_SIZE; i++){//по всем особям поколения

    }

    generation++;
}

//генерируем особь для нулевого поколения
void Bot::build_person()
{

}

/*
селекция - составляем из поколения пары для спаривания.
*/
void Bot::selection()
{

}
