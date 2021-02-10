#include "Auxil.h"

namespace auxil
{
	void start()						//старт генератора
	{
		srand((unsigned)time(NULL));
	}

	double dget(double rmin, double rmax)
	{
		return (double)rand() / RAND_MAX * (rmax - rmin) + rmin;
	}

	int iget(int rmin, int rmax)
	{
		return (int)dget((double)rmin, (double)rmax);
	}
}