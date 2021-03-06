//Разработать приложение реализующие игру «Угадайка!» на основе бинарного поиска.
//
//1. Пользователь вводит число N(может быть достаточно большое).
//
//2. Программа выводит на экран число Х(1 ≤ Х ≤ N) .
//
//3. У пользователя есть выбор одного из ответов «мало», «много», «угадал».
//
//4. В случае «мало» или «много» программа должна повторять п. 2 - 4.
//
//5. В случае «угадал» программа должна вывести на экран максимальное количество шагов при бинарном поиске от числа N и все шаги бинарного поиска. (Например, N = 100, вывести

#include <string>
#include <iostream>
#include <windows.h>
#define cls system("cls")
using namespace std;

bool isProved(string num, int start, int end);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool isGuessed = false;
	int num,
		point,
		half,
		cnt = 0;

	string checkNum;

	cout << "Выберите диапазон: ";
	getline(cin, checkNum);

	while (!isProved(checkNum, 1, 2000000))
	{
		cout << "Выберите диапазон(от 1 до 2.000.000): ";
		getline(cin, checkNum);
	}

	num = stoi(checkNum);

	cls;

	cout << "Загадайте число в диапазоне от 1 до " << num << "! А я попытаюсь отгадать его =)";
	Sleep(1200);

	int cnt_Half = 0;
	int n = num;

	while (n / 2 != 0)
	{
		cnt_Half++;
		n /= 2;
	}

	int* Halfs = new int[cnt_Half];

	n = num;
	for (int i = 0; n != 1; i++)
	{
		Halfs[i] = n / 2;
		n /= 2;
		/*cout << Halfs[i] << "\t";*/
	}
	/*Sleep(20000);*/
	int iter = 1;
	n = num / 2;

	while (!isGuessed)
	{

		if (iter >= cnt_Half)
			iter = 1;

		half = n / 2;

		cls;
		cout << "Это число " << n << "?\n"
			<< "1) Да\n"
			<< "2) Больше\n"
			<< "3) Меньше\n"
			<< "Вводите: ";

		getline(cin, checkNum);

		while (!isProved(checkNum, 1, 3))
		{
			cls;
			cout << "Это число " << num << "?\n"
				<< "1) Да\n"
				<< "2) Больше\n"
				<< "3) Меньше\n"
				<< "Вводите(1 - 3): ";

			getline(cin, checkNum);
		}

		point = stoi(checkNum);

		cls;

		switch (point)
		{
		case 1: //yes
		{
			isGuessed = true;
			break;
		}
		case 2: // more
		{
			n += Halfs[iter];
			cnt++;
			break;
		}
		case 3: // less
		{
			n -= Halfs[iter];
			cnt++;
			break;
		}
		}


		cls;
		iter++;
	}
	cout << "\nCnt = " << cnt << endl;
	delete[] Halfs;
	return 0;
}

bool isProved(string num, int start, int end)
{
	char nums[] = "0123456789";
	bool isNotNum = false;

	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (num[i] == nums[j])
			{
				isNotNum = false;
				break;
			}
			else
			{
				isNotNum = true;
			}
		}

		if (isNotNum)
		{
			return false;
		}
	}

	if (stoi(num) < start || stoi(num) > end)
	{
		return false;
	}

	return true;
}