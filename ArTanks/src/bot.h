/*

краткий план действий:

    f - функция пригодности
    f_t - необходимый уровень значений f
    p - размер попюляции
    r - доля популяции для скрещивания
    m - коэффициент мутации
    GA(f, f_t, p, r, m){
    	 P = сгенерировать начальные p гипотез (нулевое поколение)
    	 for(each h in P){посчитать f(h)}

    	 while(max(fitness(h))<f_t){
    	 	создать новое поколение:
    	 	1. селекция
    	 	2. скрещивание
    	 	3. мутация
    	 	4. обновление
    	 	5. оценка результата
    	 }

    }
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#ifndef ARTANKS_BOT_H
#define ARTANKS_BOT_H

class Bot: public Player {
public:

    int size; //длина хромосомы
    int generation = 0;
    double max_fitness = 0;
    double average_fitness = 0;
    double sum_fitness = 0;

    Bot();

    void init();
    void build_person();											//сгенерируй особь для начальной популяции
    void write_person();											//запиши особь в файл
    double results_scan();
    int find_sum_and_max_fitness();			//считаем параметры популяции
    void selection();
    void crossover();								//скрещивание
    void crossover_small();							//вспомогательная функция скрещивания
    void mutation();								//мутация
    void update();									//обновляем популяцию

private:

};

#endif //ARTANKS_BOT_H

