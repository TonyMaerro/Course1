#include <iostream>
#include "check.h"
#define MAX 20
//��������: ���, ���, ���������, ��������, ����, �����
enum sex
{
	M = 1,
	W
};

typedef string fio;
typedef int post;
typedef float salary;
typedef unsigned int exps;
typedef string address;


struct worker {
	fio FIO;
	post POST;
	salary salary;
	exps exp;
	address addrs;
	sex sex;

	void GetInfo()
	{
		cout << "FIO: \t\t\t" << FIO << endl
			<< "POST: \t\t\t";
		switch (POST)
		{
		case 1:
			cout << "�������";
			break;
		case 2:
			cout << "�������";
			break;
		case 3:
			cout << "��������";
			break;
		}
		cout << "\nSalary: \t\t" << salary << "$" << endl
			<< "Experience: \t\t" << exp << " ���" << endl
			<< "Address: \t\t" << addrs << endl;
	}

	bool operator >(worker& a)
	{
		return salary > a.salary;
	}

	bool operator <(worker& a)
	{
		return salary < a.salary;
	}

	bool operator == (worker& a)
	{
		return salary == a.salary;
	}
	string operator = (string str)
	{
		return this->FIO = str;
	}
} *workers;

void sortMethodShella(worker* Worker, int N)
{
	worker num;
	for (int i = N - 2; i >= 0; i--)
		for (int j = i; j < (N - 1) && Worker[j + 1] > Worker[j]; j++)
		{
			num = Worker[j + 1];
			Worker[j + 1] = Worker[j];
			Worker[j] = num;
		}
}

int main()
{
	setlocale(LC_ALL, "ru");
	string sPnt;
	int N = -1;
	bool isExit = false;
	while (!isExit)
	{
		cls;
		cout << "�������� ����� ����:\n"
			<< "1) �������� ����������!\n"
			<< "2) ��������� ��� �� ��������!\n"
			<< "3) �����!\n"
			<< "�������: ";

		getline(cin, sPnt);
	
		while (!isProved(sPnt, 1, 3))
		{
			cls;
			cout << "�������� ����� ����:\n"
				<< "1) �������� ����������!\n"
				<< "2) ��������� ��� �� ��������!\n"
				<< "3) �����!\n"
				<< "������� �� 1 �� 3: ";
			getline(cin, sPnt);
		}
		cls;
		switch (stoi(sPnt))
		{
		case 1: // add
		{
			if (N != -1)
			{
				cout << "�� ��� �������� ����������!" << endl;
				pause;
				break;
			}
			cout << "������� ���������� �����: ";
			getline(cin, sPnt);
			while (!isProved(sPnt, 1, 10))
			{
				cls;
				cout << "������� ���������� �����(�� 1 �� 10): ";
				getline(cin, sPnt);
			}
			cls;
			workers = new worker[stoi(sPnt)];
			N = stoi(sPnt);
			for (int i = 0; i < N; i++)
			{
				cout << "������� ��� ���������(" << i + 1 << "): ";
				string FIO;
				getline(cin, FIO);
				while (CountWord(FIO) != 3)
				{
					cls;
					cout << "������� ��� ���������: ";
					getline(cin, FIO);
				}
				correctFIO(FIO);
				workers[i] = FIO;

				cls;

				cout << "������� ��������� ���������:\n"
					<< "1) �������\n"
					<< "2) �������\n"
					<< "3) ��������\n"
					<< "�������: ";
				getline(cin, sPnt);

				while (!isProved(sPnt, 1, 3))
				{
					cls;
					cout << "������� ��������� ���������:\n"
						<< "1) �������\n"
						<< "2) �������\n"
						<< "3) ��������\n"
						<< "�������: ";
					getline(cin, sPnt);
				}
				cls;
				workers[i].POST = stoi(sPnt);

				cout << "����� ���� ���������(�� 0 �� 20 ���):  ";
				getline(cin, sPnt);
				while (!isProved(sPnt, 0, 60))
				{
					cls;
					cout << "������. ����� ���� ���������(�� 0 �� 20 ���):  ";
					getline(cin, sPnt);
				}
				workers[i].exp = stoi(sPnt);
				cls;

				cout << "������� ������:  ";
				getline(cin, workers[i].addrs);
				cls;

				workers[i].salary = float(workers[i].POST * 200) * float(float(float(workers[i].exp)*1.5) / 100 + 1); // ������ ��������: ���������� ��������
			}
			break;
		}
		case 2: // Top
		{
			if (N == -1)
			{
				cout << "�������� ����������!";
				pause;
				break;
			}
			sortMethodShella(workers, N);
			for (int i = 0; i < N; i++)
			{
				cout << "�������� " << i + 1 << ":" << endl;
				workers[i].GetInfo();
				ent; ent;
			}
			pause;
			break;
		}
		case 3: // Exit
		{
			isExit = true;
			break;
		}
		}
	}
	delete[] workers;
	pause;
	return 0;
}
