#include <iostream>
#include "check.h"
#include <stack>

int index_in_arr(char, string);

void main()
{
	setlocale(LC_ALL, "ru");
	string brackets = "({[)}]"; // массив скобок
	string str; // вводимая строка
	char symb;
	bool isNes = false; // проверка на несовпадение скобок

	str = "(({}))";

	stack<char> stack;
	for (auto i : str)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == brackets[j])
			{
				stack.push(i);
				break;
			}
		}

		for (int j = 3; j < brackets.size(); j++)
		{
			if (i == brackets[j])
			{
				if (stack.empty())
				{
					isNes = true;
					break;
				}
				symb = stack.top();
				stack.pop();
				if (symb != brackets[index_in_arr(i, brackets) - 3])
				{
					isNes = true;
				}
				break;
			}
		}
		if (isNes)
		{
			break;
		}
	}
	if (!stack.empty())
		isNes = true;

	cout << ((isNes) ? "Ошибка в расставлении скобок!\n" : "Ошибок со скобками нет!\n");
}

int index_in_arr(char symb, string Arr) // поиск индекса элемента в массиве
{
	int cnt = 0;
	for (auto i : Arr)
	{
		if (i == symb)
		{
			break;
		}
		cnt++;
	}
	return cnt;
}