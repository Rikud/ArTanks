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

void Bot::update()
{

}

//записываем особь f в файл для последующей интерпретации в танке
void Bot::write_person()
{

}

/* смотрим, какие у нас получились особи. ищем альфа-самца, 
считаем общее значение */
int Bot::find_sum_and_max_fitness()
{

}

// мутация
void Bot::mutation()
{

}

/* непосредственное скрещивание конкретных двух строк */
void Bot::crossover_small()
{

}

* кроссовер - скрещивание особей поколения */
void Bot::crossover()
{

}
