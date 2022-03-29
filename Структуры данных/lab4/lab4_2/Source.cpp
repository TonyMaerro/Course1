#include <iostream>
#include "check.h"

//�� ����������� ��������� ��������� ������������ ���������.��������� ���������� ����� �������� ������� ���������� �������.�������� ��������� ��������� ��������, ���������� ������ �� ���� III �������.
//�� ����������� ��������� ���������� ���������� ��������.
//����: ����������� ����� ��������(N < 10000) � ����� N ����������� ����� � ���������� ����������(������������� �� 1 �� 100)
//����� : ���� ����� � ����� ��������.


void main()
{
	setlocale(LC_ALL, "ru");
	unsigned int N,
			 changes = 0,
		     cnt = 0,
		     maxPoint = 100;
	int* results;
	string check;
	cout << "������� ���������� ����������: ";
	getline(cin, check);
	while (!isProved(check, 1, 10000))
	{
		cls;
		cout << "������� ���������� ����������(1 - 10000): ";
		getline(cin, check);
	}
	cls;
	N = stoi(check);
	results = new int[N];

	for (int i = 0; i < N; i++)
	{
		results[i] = rand() % maxPoint + 1;
		cout << "������ " << i + 1 << " = " << results[i] << "\t\t\t\t";
		if ((i + 1) % 3 == 0) ent;
	}

	sortMethodShella(results, N);

	for (int i = N - 1; i > 0; i--)
	{
		if (changes == 3)
		{
			break;
		}
		else
		{
			cnt++;
			if (i == 1 && results[i] == results[0]) cnt++;
		}
		if (results[i] != results[i - 1])
		{
			changes++;
		}
	}

	cout << "\n\n\n\n���������� ��������:\t\t" << cnt << endl;

	delete[] results;
	
}