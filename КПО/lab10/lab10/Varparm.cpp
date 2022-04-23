#include "Varparm.h"

int Varparm::ivarparm(int n, ...)
{
	int* first = &n + 1;
	int sum = 0;
	for (int* p = first; p < first + n; p++)
	{
		sum += *p;
	}
	return sum;
}

int Varparm::svarparm(short n, ...)
{
	short* first = &n + 1;
	short max = 0;
	for (short* p = first; p < first + n; p++)
	{
		if (*p > max)
		{
			max = *p;
		}
	}
	return max;
}

double Varparm::fvarparm(float n, ...)
{
	float* first = &n;
	float sum = 0;
	while (first != (&n + int(n) - 1))
	{
		sum += *first;
		first += 1;
	}
	return sum;
}

double Varparm::dvarparm(double n, ...)
{
	double* first = &n;
	double sum = 0;
	while (first != (&n + int(n) - 1))
	{
		sum += *first;
		first += 1;
	}
	return sum;
}
