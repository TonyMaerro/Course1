#include <iostream>
using namespace std;
#include "stdafx.h"
using namespace Dictionary;

void main()
{
	setlocale(LC_ALL, "ru");
	try
	{
#if defined(TEST_CREATE_01)
		Instance d1 = Create("������ffffffffffffffffffffffffffffffffffffffffffffffffffffa������", 5);
#elif defined(TEST_CREATE_02)
		Instance d1 = Create("������a������", 1000);
#else 
		Instance d1 = Create("������a������", 5);
#endif
		Entry e1 = { 1, "�������" },
			  e2 = { 2, "�������"},
			  e3 = {3, "�����"},
			  e4 = { 4, "�������"},
#if defined(TEST_ADDENTRY_04)
			  e5 = { 2, "��������"};
#else 
			  e5 = { 5, "��������" };
#endif
		addEntry(d1, e1);
		addEntry(d1, e2);
		addEntry(d1, e3);
		addEntry(d1, e4);
		addEntry(d1, e5);
#if defined(TEST_ADDENTRY_03)
		addEntry(d1, e5);
#endif
		
#if defined(TEST_GETENTRY_05)
		Entry ex2 = GetEntry(d1, 4000);
#else
		Entry ex2 = GetEntry(d1, 4);
#endif
#if defined(TEST_DELENTRY_06)
		DelEntry(d1, 20000);
#else
		DelEntry(d1, 2);
#endif
#if defined(TEST_UPDENTRY_08)
		Entry newentry1 = { 1, "�����" };
#else 
		Entry newentry1 = { 6, "�����" };
#endif
#if defined(TEST_UPDENTRY_07)
		UpdEntry(d1, 30000, newentry1);
#else
		UpdEntry(d1, 3, newentry1);
#endif
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
