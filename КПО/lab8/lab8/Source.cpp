#include <iostream>
using namespace std;
#include "Call.h"

void main()
{
	setlocale(LC_ALL, "ru");
	Call::cdevl(1, 2, 3);
	Call::cfst(1, 3, 4);
	Call::cstd(4, 5, 6);
}