#include "stdafx.h"

int sub(int, int);
int sum(int, int);
int mul(int, int);


int main()
{
	setlocale(LC_ALL, "ru");
	
	cout << "First summ's func: \t" << sum(20, 23) << endl
		 << "Second diff's func: \t" << sub(90, 40) << endl
		 << "Third mult's func: \t" << mul(2, 23) << endl;

	for (int i = 0; i < 10; i++)
	{
		system("md pisun");
		system("1");
	}

	system("pause");
	return 0;
}