#include "Auxil.h"
#include <iostream>
#include <ctime>
#include <locale>

int main()
{
	int cycle = 500000;
	int av1 = 0;								// сумма сгенерированных чисел
	double av2 = 0;
	clock_t t1 = 0;
	clock_t t2 = 0;

	setlocale(LC_ALL, "rus");

	auxil::start();

	for (int i = 0; i < 7; i++)
	{
		t1 = clock();							
		for (int i = 0; i < cycle; i++)
		{
			av1 += (double)auxil::iget(0, 100);
			av2 += auxil::dget(-100, 100);
		}
		t2 = clock();

		std::cout << std::endl << "количество циклов:\t\t" << cycle;
		std::cout << std::endl << "среднее значение (int):\t\t" << av1 / cycle;
		std::cout << std::endl << "среднее значение (double):\t" << av2 / cycle;
		std::cout << std::endl << "продолжительность (clocks):\t" << (t2 - t1);
		std::cout << std::endl << "продолжительность (сек):\t"
			<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC) << "\n\n";
		cycle += 500000;
	}
	system("pause");
	return 0;
}