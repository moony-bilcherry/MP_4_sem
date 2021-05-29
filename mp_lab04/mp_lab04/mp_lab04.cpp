#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Levenstein.h"
int main()
{
    setlocale(LC_ALL, "rus");

    std::cout << "L(ель,дрель) = " << levenshtein(3, "ель", 5, "дрель") << std::endl << std::endl;

    clock_t t1 = 0, t2 = 0, t3, t4;

    char STR1[300], STR2[250];

    std::cout << "\tСТРОКА 1 [300]:\n";
    for (int i = 0; i < sizeof(STR1); i++) {
        STR1[i] = (char)((int)'a' + (rand() % 26));
        std::cout << STR1[i];
        if ((i + 1) % 50 == 0) std::cout << std::endl;
    }
    std::cout << "\n\tСТРОКА 2 [250]:\n";
    for (int i = 0; i < sizeof(STR2); i++) {
        STR2[i] = (char)((int)'a' + (rand() % 26));
        std::cout << STR2[i];
        if ((i + 1) % 50 == 0) std::cout << std::endl;
    }

    int STR1_len = sizeof(STR1), STR2_len = sizeof(STR2);
    int STR1_size[] = { STR1_len / 25, STR1_len / 20, STR1_len / 15, STR1_len / 10, STR1_len / 5, STR1_len / 2, STR1_len };
    int STR2_size[] = { STR2_len / 25, STR2_len / 20, STR2_len / 15, STR2_len / 10, STR2_len / 5, STR2_len / 2, STR2_len };

    std::cout << std::endl << "\n\tРасстояние Левенштейна" << std::endl;
    std::cout << std::left << std::setw(11) << "   длина" << "|\t";
    std::cout << std::left << std::setw(10) << "рекурсия" << "|\t";
    std::cout << "дин. программа\n";

    for (int i = 0; i < std::min(STR1_len, STR2_len); i++)
    {
        std::cout << std::right << std::setw(5) << STR2_size[i] << "/" << std::left << std::setw(5) << STR1_size[i] << "|\t";
        t1 = clock(); 
        levenshtein_r(STR1_size[i], STR1, STR2_size[i], STR2);
        t2 = clock();

        std::cout << std::left << std::setw(10) << (t2 - t1) << "|\t";
        t3 = clock(); 
        levenshtein(STR1_size[i], STR1, STR2_size[i], STR2);
        t4 = clock();
        
        std::cout << (t4 - t3) << std::endl;
    }
    system("pause");
    return 0;
}