#include <iostream>
#include "check.h"
#define MAX 20
//работник: ФИО, пол, должность, зарплата, стаж, адрес
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
			cout << "Уборщик";
			break;
		case 2:
			cout << "Инженер";
			break;
		case 3:
			cout << "Директор";
			break;
		}
		cout << "\nSalary: \t\t" << salary << "$" << endl
			<< "Experience: \t\t" << exp << " лет" << endl
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
		cout << "Выберите пункт меню:\n"
			<< "1) Добавить работников!\n"
			<< "2) Составить топ по зарплате!\n"
			<< "3) Выход!\n"
			<< "Введите: ";

		getline(cin, sPnt);
	
		while (!isProved(sPnt, 1, 3))
		{
			cls;
			cout << "Выберите пункт меню:\n"
				<< "1) Добавить работников!\n"
				<< "2) Составить топ по зарплате!\n"
				<< "3) Выход!\n"
				<< "Введите от 1 до 3: ";
			getline(cin, sPnt);
		}
		cls;
		switch (stoi(sPnt))
		{
		case 1: // add
		{
			if (N != -1)
			{
				cout << "Вы уже добавили работников!" << endl;
				pause;
				break;
			}
			cout << "Сколько работников будет: ";
			getline(cin, sPnt);
			while (!isProved(sPnt, 1, 10))
			{
				cls;
				cout << "Сколько работников будет(от 1 до 10): ";
				getline(cin, sPnt);
			}
			cls;
			workers = new worker[stoi(sPnt)];
			N = stoi(sPnt);
			for (int i = 0; i < N; i++)
			{
				cout << "Введите ФИО работника(" << i + 1 << "): ";
				string FIO;
				getline(cin, FIO);
				while (CountWord(FIO) != 3)
				{
					cls;
					cout << "Введите ФИО работника: ";
					getline(cin, FIO);
				}
				correctFIO(FIO);
				workers[i] = FIO;

				cls;

				cout << "Введите должность работника:\n"
					<< "1) Уборщик\n"
					<< "2) Инженер\n"
					<< "3) Директор\n"
					<< "Введите: ";
				getline(cin, sPnt);

				while (!isProved(sPnt, 1, 3))
				{
					cls;
					cout << "Введите должность работника:\n"
						<< "1) Уборщик\n"
						<< "2) Инженер\n"
						<< "3) Директор\n"
						<< "Введите: ";
					getline(cin, sPnt);
				}
				cls;
				workers[i].POST = stoi(sPnt);

				cout << "Каков стаж работника(от 0 до 20 лет):  ";
				getline(cin, sPnt);
				while (!isProved(sPnt, 0, 60))
				{
					cls;
					cout << "ошибка. Каков стаж работника(от 0 до 20 лет):  ";
					getline(cin, sPnt);
				}
				workers[i].exp = stoi(sPnt);
				cls;

				cout << "Введите адресс:  ";
				getline(cin, workers[i].addrs);
				cls;

				workers[i].salary = float(workers[i].POST * 200) * float(float(float(workers[i].exp)*1.5) / 100 + 1); // Первая операция: вычисление зарплаты
			}
			break;
		}
		case 2: // Top
		{
			if (N == -1)
			{
				cout << "Добавьте работников!";
				pause;
				break;
			}
			sortMethodShella(workers, N);
			for (int i = 0; i < N; i++)
			{
				cout << "Работник " << i + 1 << ":" << endl;
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
