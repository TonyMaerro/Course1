#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

bool isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int whatDay(short day, short mon, short year)
{
	short daysInMon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	short cntDays = day;

	if (isLeapYear(year))
	{
		daysInMon[1] = 29;
		for (int i = 1; i < mon; i++)
		{
			if (mon == 1)
				break;
			cntDays += daysInMon[i-1];
		}
	}
	else
	{
		for (int i = 1; i < mon; i++)
		{
			if (mon == 1)
				break;
			cntDays += daysInMon[i-1];
		}
	}
	return cntDays;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	string date;
	date = "12021999";

	bool dateTrue = false;
	

	short day = 1,
		  mon = 1,
		  year = 2;

	string dayS,
		   monS,
		   yearS;
		   
	string cash1,
		   cash2;

	while (!dateTrue)
	{
		cout << "\nAaaaeoa aaoo: ";
		getline(cin, date);

		if (date.size() != 8)
		{
			cout << "Aaaaeoa ei??aeoio? eioi?iaoe?!" << endl;
			continue;
		}


		for (int i = 0; i < date.size(); i++)
		{
			char symb = date[i];

			if (dayS > "31")
			{
				cout << "Aaaaeoa ei??aeoio? eioi?iaoe?!" << endl;
				dateTrue = false;
				break;
			}

			if (monS > "12" && monS <= "0" && monS.size() != 2)
			{
				cout << "Aaaaeoa ei??aeoio? eioi?iaoe?!" << endl;
				dateTrue = false;
				break;
			}

			if (symb > '9' && symb < '0')
			{
				cout << "Aaaaeoa ei??aeoio? eioi?iaoe?!" << endl;
				dateTrue = false;
				break;
			}
			else
			{
				cash1 = date[0];
				cash2 = date[1];
				dayS = cash1 + cash2;
				day = stoi(dayS);

				cash1 = date[2];
				cash2 = date[3];
				monS = cash1 + cash2;
				mon = stoi(monS);

				cash1 = date[4];
				cash2 = date[5];
				yearS = cash1 + cash2;
				cash1 = date[6];
				cash2 = date[7];
				yearS += cash1 + cash2;
				year = stoi(yearS);

				short daysInMon[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
				bool err = false;

				if (day == 0 || mon == 0)
				{
					cout << "Aaaaeoa ei??aeoiua aaiiua!" << endl;
					break;
				}

				if (isLeapYear(year))
					daysInMon[1] = 29;

				for (int i = 0; i < 12; i++)
				{
					if (mon == i + 1)
					{
						if (day > daysInMon[i])
						{
							cout << "\nIoeaea. Eiee?anoai aiae a ianyoa iaiuoa!" << endl; 
							err = true;
							break;
						}
					}
				}

				if (err)
					break;

				dateTrue = true;
			}
		}
	}

	cout << endl;

	if (isLeapYear(year))
	{
		cout << "Yoi aenieiniue aia!" << endl;
	}
	else
	{
		cout << "Yoi ia aenieiniue aia!" << endl;
	}

	cout << "Yoio aaiu " << whatDay(day, mon, year) << " a aiao" << endl;

	short bDay = 30,
		  bMon = 01,
		  bYear = 2023;

	int countDays;

	if (isLeapYear(year)) 
	{
		countDays = abs(whatDay(day, mon, year) + year*366 - whatDay(bDay, bMon, bYear) - bYear * 365);
	}
	else
	{
		countDays = abs(whatDay(day, mon, year) + year * 365 - whatDay(bDay, bMon, bYear) - bYear * 365);
	}

	cout << "Eiee?anoai aiae ai aiy ?i?aaiey:  " << countDays << endl;
}