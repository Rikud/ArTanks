//
// Created by Alex on 18.11.2017.
//

#include "bot.h"

Bot::Bot(Tank *val) : Player (val)
{
    size = HEAD_SIZE * MAX_ARN + 1;
}

void Bot::genGeneration()
{
    for(i = 0; i < POPULATION_SIZE; i++){//по всем особям поколения

        build_person(f[i]); //сгенерировать особь нулевого поколения
        write_person(f[i]); //записать ее в файл

        generate_battle(x2, y2, x1, y1);

        fitness[i] = results_scan(); //и посмотреть что вышло

    }

    best_num = find_sum_and_max_fitness(fitness, f);

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
