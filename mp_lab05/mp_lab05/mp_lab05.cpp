#include <iostream>
#include "Graph.h"
#include "BFS.h"
#include "DFS.h"

//     алгоритмы BFS и DFS 
int main()
{
	setlocale(LC_ALL, "rus");

	std::cout << "\t\tВариант 10\n\n";

	// матрица смежности из задания, 10 вариант:
	int V10[7][7] = {
		{0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 0},
	};

	graph::AMatrix matr(7, (int*)V10);
	std::cout << "Матрица смежности:";
	for (int i = 0; i < matr.n_vertex; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < matr.n_vertex; j++) std::cout << matr.get(i, j) << " ";
	};

	graph::AList list(matr);
	std::cout << "\n\nСписки смежных вершин:";
	for (int i = 0; i < matr.n_vertex; i++)
	{
		std::cout << std::endl << i << ": ";
		for (int j = 0; j < list.size(i); j++) std::cout << list.get(i, j) << " ";
	}

	BFS bfs(list, 0);
	std::cout << "\n\nПоиск в ширину:\n";
	int temp;
	while ((temp = bfs.get()) != BFS::NIL) 
		std::cout << temp << " ";
	
	DFS dfs(list);
	std::cout << "\n\nПоиск в глубину: (выводится в обратном порядке)\n";
	for (int i = 0; i < list.n_vertex; i++) 
		std::cout << dfs.get(i) << " ";

	std::cout << "\n\nТопологическая сортировка:\n";
	for (std::vector <int>::iterator i(dfs.topological_sort.begin()); i != dfs.topological_sort.end(); ++i) 
		std::cout << *i << ' ';
	std::cout << std::endl;

	system("pause");
	return 0;
}
