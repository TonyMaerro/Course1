#include <iostream>
#include "check.h"
#include <stack>

int index_in_arr(char, string);

void main()
{
	setlocale(LC_ALL, "ru");
	string brackets = "({[)}]"; // ������ ������
	string str; // �������� ������
	char symb;
	bool isNes = false; // �������� �� ������������ ������

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

	cout << ((isNes) ? "������ � ������������ ������!\n" : "������ �� �������� ���!\n");
}

int index_in_arr(char symb, string Arr) // ����� ������� �������� � �������
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