//#include <iostream>
//#include <string>
//using namespace std;
//
//bool isLeapYear(int year)
//{
//	if (year % 4 == 0 && year % 100 != 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int whatDay(short day, short mon, short year)
//{
//	short daysInMon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//	short cntDays = day;
//
//	if (isLeapYear(year))
//	{
//		daysInMon[1] = 29;
//		for (int i = 1; i < mon; i++)
//		{
//			if (mon == 1)
//				break;
//			cntDays += daysInMon[i-1];
//		}
//	}
//	else
//	{
//		for (int i = 1; i < mon; i++)
//		{
//			if (mon == 1)
//				break;
//			cntDays += daysInMon[i-1];
//		}
//	}
//	return cntDays;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	string date;
//	date = "12021999";
//
//	bool dateTrue = false;
//	
//
//	short day = 1,
//		  mon = 1,
//		  year = 2;
//
//	string dayS,
//		   monS,
//		   yearS;
//		   
//	string cash1,
//		   cash2;
//
//	while (!dateTrue)
//	{
//		cout << "\nВведите дату: ";
//		getline(cin, date);
//
//		if (date.size() != 8)
//		{
//			cout << "Введите корректную информацию!" << endl;
//			continue;
//		}
//
//
//		for (int i = 0; i < date.size(); i++)
//		{
//			char symb = date[i];
//
//			if (dayS > "31")
//			{
//				cout << "Введите корректную информацию!" << endl;
//				dateTrue = false;
//				break;
//			}
//
//			if (monS > "12" && monS <= "0" && monS.size() != 2)
//			{
//				cout << "Введите корректную информацию!" << endl;
//				dateTrue = false;
//				break;
//			}
//
//			if (symb > '9' && symb < '0')
//			{
//				cout << "Введите корректную информацию!" << endl;
//				dateTrue = false;
//				break;
//			}
//			else
//			{
//				cash1 = date[0];
//				cash2 = date[1];
//				dayS = cash1 + cash2;
//				day = stoi(dayS);
//
//				cash1 = date[2];
//				cash2 = date[3];
//				monS = cash1 + cash2;
//				mon = stoi(monS);
//
//				cash1 = date[4];
//				cash2 = date[5];
//				yearS = cash1 + cash2;
//				cash1 = date[6];
//				cash2 = date[7];
//				yearS += cash1 + cash2;
//				year = stoi(yearS);
//
//				short daysInMon[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//				bool err = false;
//
//				if (day == 0 || mon == 0)
//				{
//					cout << "Введите корректные данные!" << endl;
//					break;
//				}
//
//				if (isLeapYear(year))
//					daysInMon[1] = 29;
//
//				for (int i = 0; i < 12; i++)
//				{
//					if (mon == i + 1)
//					{
//						if (day > daysInMon[i])
//						{
//							cout << "\nОшибка. Количество дней в месяце меньше!" << endl; 
//							err = true;
//							break;
//						}
//					}
//				}
//
//				if (err)
//					break;
//
//				dateTrue = true;
//			}
//		}
//	}
//
//	cout << endl;
//
//	if (isLeapYear(year))
//	{
//		cout << "Это високосный год!" << endl;
//	}
//	else
//	{
//		cout << "Это не високосный год!" << endl;
//	}
//
//	cout << "Этот день " << whatDay(day, mon, year) << " в году" << endl;
//
//	short bDay = 30,
//		  bMon = 01,
//		  bYear = 2023;
//
//	int countDays;
//
//	if (isLeapYear(year)) 
//	{
//		countDays = abs(whatDay(day, mon, year) + year*366 - whatDay(bDay, bMon, bYear) - bYear * 365);
//	}
//	else
//	{
//		countDays = abs(whatDay(day, mon, year) + year * 365 - whatDay(bDay, bMon, bYear) - bYear * 365);
//	}
//
//	cout << "Количество дней до дня рождения:  " << countDays << endl;
//}

#include <iostream>
#include <stdio.h>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE* A, * B;
	size_t fSizeOfA;
	long endPos;
	errno_t err;
	err = fopen_s(&A, "A.txt", "w");
	if (err != 0)
	{
		perror("ошибка открытия a.txt");
		return;
	}
	cout << "Введите размер матрицы:" << endl;
	int n; cin >> n;
	fprintf(A, "%d\t", n);
	int* massiv = new int[n * n];
	cout << "Введите элементы массива: " << endl;
	for (int g = 0, u = 0; g < n; g++)
	{
		for (int i = 0; i < n; i++, u++)
		{
			cin >> massiv[u];
			fprintf(A, "%d\t", massiv[u]);
		}
	}

	for (int g = 0, u = 0; g < n; g++)
	{
		for (int i = 0; i < n; i++, u++)
		{
			cout << massiv[u];
		}
		cout << endl;
	}

	delete[] massiv;
	fclose(A);


	err = fopen_s(&A, "A.txt", "r");
	if (err != 0)
	{
		perror("ошибка открытия a.txt");
		return;
	}
	//определяем размер
	fseek(A, 0L, SEEK_END);
	endPos = ftell(A);
	fseek(A, 0L, SEEK_SET);
	if (!fopen_s(&B, "B.txt", "w"))
	{
		int x;
		fscanf_s(A, "%d", &x); //узнаем размер массива
		int** arr = new int* [x];
		for (int i = 0; i < x; i++)
			arr[i] = new int[x];
		for (int u = 0; u < x; u++) //считывание данных из файлов в массив
			for (int i = 0; i < x; i++)
			{
				fscanf_s(A, "%d", &(arr[u][i]));
			}

		cout << "Итоговая матрица: " << endl;
		for (int g = 0; g < x; g++)
		{
			for (int i = 0; i < x; i++)
			{
				cout << arr[g][i] << " ";
			}
			cout << endl;
		}

		cout << "Введите k-й столбец(он появится в файле В): " << endl;
		int k; cin >> k;
		for (int i = 0; i < x; i++)
		{
			fprintf_s(B, "%d ", arr[i][k - 1]);
		}
		fclose(A);
		fclose(B);

		delete[] arr;

		cout << "Файл был успешно создан" << endl;
	}
	else {
		cout << "Ошибка создания файла" << std::endl;
		return;
	}
	system("pause");
}
