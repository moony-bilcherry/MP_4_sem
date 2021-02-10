#include <iostream>
#include "Combi1.h"
#include <tchar.h>
#include "Knapsack.h"
#include "Auxil.h"

#define ITEM_MAX_AMOUNT 18                // количество предметов (шт)
#define KNAP_MAX_WEIGHT 300               // вместимость рюкзака (кг)

/*(Вариант 2, 6, 10, 14) упрощенную о рюкзаке (веса предметов и их стоимость сгенерировать случайным образом:
вместимость рюкзака 300 кг, веса предметов 10 – 300 кг, стоимость предметов 5 – 55 у.е.; количество предметов – 18 шт.);*/

int main()
{
    setlocale(LC_ALL, "rus");
    int item_weight[ITEM_MAX_AMOUNT],      // вес предмета каждого типа  
        item_price[ITEM_MAX_AMOUNT];       // стоимость предмета каждого типа 
    short item_instance[ITEM_MAX_AMOUNT];                       // количество предметов каждого типа  {0,1}  

    auxil::start();
    for (int i = 0; i < ITEM_MAX_AMOUNT; i++) {
        item_weight[i] = (double)auxil::iget(10, 300);
        item_price[i] = (double)auxil::iget(5, 55);
    }

    int optimal_weight = knapsack_s(KNAP_MAX_WEIGHT, ITEM_MAX_AMOUNT, item_weight, item_price, item_instance);

    std::cout << "\t\tУпрощенная задача о рюкзаке";
    std::cout << std::endl << "- количество предметов (шт):\t\t" << ITEM_MAX_AMOUNT;
    std::cout << std::endl << "- вместимость рюкзака (кг):\t\t" << KNAP_MAX_WEIGHT;

    std::cout << std::endl << "- размеры предметов (кг):\t\t";
    for (int i = 0; i < ITEM_MAX_AMOUNT; i++) std::cout << item_weight[i] << " ";
    std::cout << std::endl << "- стоимости предмета ($):\t\t";
    for (int i = 0; i < ITEM_MAX_AMOUNT; i++) std::cout << item_price[i] << " ";
    std::cout << std::endl << "- оптимальная стоимость рюкзака ($):\t" << optimal_weight;
    std::cout << std::endl << "- вес рюкзака (кг):\t\t\t";
    int s = 0; for (int i = 0; i < ITEM_MAX_AMOUNT; i++) s += item_instance[i] * item_weight[i];
    std::cout << s;
    std::cout << std::endl << "- выбраны предметы:\t\t\t";
    for (int i = 0; i < ITEM_MAX_AMOUNT; i++) std::cout<< item_instance[i] << " ";
    std::cout << std::endl << std::endl;
    system("pause");
    return 0;
}
