//В сети магазинов "ФИТ-Аудио" проводится рекламная акция.Каждый второй товар – бесплатно.Естественно,
//кассирам дано указание пробивать товары в таком порядке, чтобы магазин потерял как можно меньше денег.
//По списку товаров определите максимальную сумму в чеке.
//
//Порядок пробивания на кассе и число – максимальная сумма чека.
#include  <iostream>
#include  "check.h"

void main()
{
	setlocale(LC_ALL, "ru");
	string check;
	unsigned int num,
		sum = 0;

	cout << "Введите, сколько элементов будет в массиве:  ";
	getline(cin, check);
	while (!isProved(check, 1, 10000))
	{
		cls;
		cout << "Введите, сколько элементов будет в массиве(1 - 10000):  ";
		getline(cin, check);
	}
	num = stoi(check);
	cls;
	int* arr = new int[num];

	for (int i = 0; i < num; i++)
	{
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << ";  ";
	}

	sortMethodPuz(arr, num);
	ent; ent;

	cout << "Порядок:\t\t\t\t";
	for (int i = 0, start = 0, end = num - 1; i < num; i++)
	{
		if ((i + 1) % 2 == 0)
		{
			cout << arr[start++] << ";   ";
		}
		else
		{
			sum += arr[end];
			cout << arr[end--] << ";   ";
		}
	}
	cout << "\nМаксимальная сумма:\t\t\t" << sum;
	ent;

	delete[] arr;
}