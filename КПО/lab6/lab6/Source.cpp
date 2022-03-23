#include <iostream>
using namespace std;
#include "stdafx.h"
using namespace Dictionary;

void main()
{
	setlocale(LC_ALL, "ru");
	try
	{
		Instance d1 = Create("Преподaватели", 5);
		Entry e1 = { 1, "Гладкий" },
			  e2 = { 2, "Веялкин"},
			  e3 = {3, "Мищук"},
			  e4 = { 4, "Белодед"},
			  e5 = { 5, "Наркевич"};

		addEntry(d1, e1);
		addEntry(d1, e2);
		addEntry(d1, e3);
		addEntry(d1, e4);
		addEntry(d1, e5);
		
		Entry ex2 = GetEntry(d1, 4);
		DelEntry(d1, 2);
		Entry newentry1 = { 6, "Гурин" };
		UpdEntry(d1, 3, newentry1);
		Print(d1);

		Instance d2 = Create("Студенты", 5);
		Entry s1 = { 1, "Иванов" },
			  s2 = { 2, "Петров"},
			  s3 = { 3, "Гайков"};
		addEntry(d2, s1);
		addEntry(d2, s2);
		addEntry(d2, s3);

		Entry newentry3 = { 3, "Николаев" };
		UpdEntry(d2, 3, newentry3);
		Print(d2);
		Delete(d1);
		Delete(d2);
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	system("pause");
}
