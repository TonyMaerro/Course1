#include <iostream>
using namespace std;
#include "stdafx.h"
using namespace Dictionary;

void main()
{
	setlocale(LC_ALL, "ru");
	try
	{
		Instance d1 = Create("������a������", 5);
		Entry e1 = { 1, "�������" },
			  e2 = { 2, "�������"},
			  e3 = {3, "�����"},
			  e4 = { 4, "�������"},
			  e5 = { 5, "��������"};

		addEntry(d1, e1);
		addEntry(d1, e2);
		addEntry(d1, e3);
		addEntry(d1, e4);
		addEntry(d1, e5);
		
		Entry ex2 = GetEntry(d1, 4);
		DelEntry(d1, 2);
		Entry newentry1 = { 6, "�����" };
		UpdEntry(d1, 3, newentry1);
		Print(d1);

		Instance d2 = Create("��������", 5);
		Entry s1 = { 1, "������" },
			  s2 = { 2, "������"},
			  s3 = { 3, "������"};
		addEntry(d2, s1);
		addEntry(d2, s2);
		addEntry(d2, s3);

		Entry newentry3 = { 3, "��������" };
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
