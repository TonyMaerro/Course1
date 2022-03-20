#include <iostream>
using namespace std;

typedef unsigned char day;
typedef unsigned char mon;
typedef unsigned int year;

struct Date
{
	day dd[3];
	mon mm[3];
	year yyyy;

	bool operator >(Date& a)
	{
		return (yyyy > a.yyyy);
	}
	bool operator <(Date& a)
	{
		return (yyyy < a.yyyy);
	}
	bool operator ==(Date& a)
	{
		return (yyyy == a.yyyy);
	}
};

int main()
{
	Date date1 = { "11", "12", 2003},
		 date2 = {"12", "01", 1999},
		 date3 = {"01", "03", 2020};

	cout << "Date1 > Date2: ";
	if (date1 > date2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "Date1 < Date2: ";
	if (date1 < date2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "Date1 = Date2: ";
	if (date1 == date2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "Date1 = Date3: ";
	if (date1 == date3)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
};
