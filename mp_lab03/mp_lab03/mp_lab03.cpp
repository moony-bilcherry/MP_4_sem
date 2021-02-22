#include <iostream>
#include <iomanip> 
#include <tchar.h>
#include <stdio.h>
#include "Salesman.h"

#define SIZE 5          // количество городов

int main()
{
    setlocale(LC_ALL, "rus");
    int n = 6;
    // массив настояний
    int matrix[SIZE][SIZE] =    { //0   1    2    3     4        
                                { INF, 2*n, 21+n, INF, n},          // 0
                                { n, INF, 15+n, 68-n, 84-n},        // 1
                                { 2+n, 3*n, INF, 86, 49+n},         // 2 
                                { 17+n, 58-n, 4*n, INF, 3*n},       // 3
                                { 93-n, 66+n, 52, 13+n, INF}        // 4
                                }; 
    int route[SIZE];                     // результат 
    int length = salesman(SIZE, (int*)matrix, route);

    std::cout << "\t\t ЛР3. Задача коммивояжера";
    std::cout << std::endl << "* количество  городов:\t" << SIZE;
    std::cout << std::endl << "* матрица расстояний:";

    for (int i = 0; i < SIZE; i++) {
        std::cout << "\n\t";
        for (int j = 0; j < SIZE; j++)
            if (matrix[i][j] != INF) std::cout << std::setfill(' ') << std::setw(3) << std::left << matrix[i][j] << "  ";
            else std::cout << std::setw(3) << "INF" << "  ";
    }
    std::cout << std::endl << "* оптимальный маршрут:\t";
    for (int i = 0; i < SIZE; i++) std::cout << route[i] + 1<< " ---> "; 
    std::cout << 1;

    std::cout << std::endl << "* длина маршрута:\t" << length << std::endl;

    system("pause");
    return 0;
}

