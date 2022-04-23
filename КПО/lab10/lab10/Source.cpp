#include <iostream>
#include "Varparm.h"

void main()
{
	Varparm::ivarparm(4, 1, 2, 3, 4);
	Varparm::svarparm(6, 2, 3, 4, 5, 6, 1);
	Varparm::fvarparm(3, 1, 2, FLT_MAX);
	Varparm::dvarparm(2, 2, DBL_MAX);
}