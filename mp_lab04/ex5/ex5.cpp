#include <cmath>
#include <memory.h>
#include <iostream>
#include "MultyMatrix.h"   // умножение матриц 

#define N 6
int main()
{
	setlocale(LC_ALL, "rus");

	int Mc[N + 1] = { 100,15,20,43,70,40,71 },
		Ms[N][N], 
		r = 0, rd = 0;
	clock_t t1 = 0, t2 = 0, t3, t4;

	memset(Ms, 0, sizeof(int) * N * N);

	std::cout << "\t\tРАССТАНОВКА СКОБОК\n" << "* Размерности матриц: " << std::endl;
	
	for (int i = 1; i <= N; i++) std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";

	std::cout << "\n\n\tРекурсивное решение\n";
	t1 = clock();
	r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
	t2 = clock();
	std::cout << "Время выполнения: " << t2 - t1 << "\n";
	std::cout << "Мин. количество операций умножения: " << r;
	/*std::cout << "\n* Матрица S:" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}*/

	memset(Ms, 0, sizeof(int) * N * N);
	std::cout << "\n\n\tДинамическое программирование\n";
	t3 = clock();
	rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
	t4 = clock();
	std::cout << "Время выполнения: " << t4 - t3 << "\n";
	std::cout << "Мин. количество операций умножения: " << rd;
	/*std::cout << "\n* Матрица S:" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}*/
	std::cout << std::endl;
	system("pause");

	return 0;
}
