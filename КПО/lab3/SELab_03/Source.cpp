#include <iostream>
#include <windows.h>
using namespace std;

void func()
{
	cout << "Функция вызвана!\n\n";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool val1 = true,
		 val2 = false;

	char symbEN = 'a',
		 symbRU = 'а';

	wchar_t sEN = 'G',
		    sRU = 'Г';

	short x = 14, // 0x000e
		  _x = -14; // 0xffff2

	/*while (x > _x)
	{
		_x = x;
		x++;
	}

	char max[10],
		 min[10];

	_itoa_s(_x, max, 16);
	_itoa_s(x, min, 16);

	cout << _x << " " << max << endl <<x << " " << min << endl;*/

	short max = 0x7fff,
		  min = 0xffff8000;

	unsigned short mins = 0x0;
	/* a,
				   b;

	a = 10;
	b = 11;

	while (a < b)
	{
		b = a--;
	}

	cout << b;*/

	int Y = 15, // 0xffffffff
		_Y = -15; // 0xfffffff1	

	/*char _Ystr[10];
	_itoa_s(-14, _Ystr, 16);
	cout << _Ystr;*/

	int maxInt,
		minInt,
		a = 1,
		b = 0;

	/*while (a > b)
	{
		b = a++;
	}*/

	/*char _Ystr[10];
	_itoa_s(b, _Ystr, 16);
	cout << _Ystr << endl;
	_itoa_s(a, _Ystr, 16);
	cout << _Ystr << endl;*/

	maxInt = 0x7fffffff;
	minInt = 0x80000000;

	unsigned int maxUnInt = 0xffffffff,
				 minInInt = 0x00000000,
				 c, d;

	/*c = 1;
	d = 0;

	while (c > d)
	{
		d = c++;
	}
	
	char str[10];
	_itoa_s(d, str, 16);
	cout << str;*/

	long Z = 0x10, // 0x10
		_z = 0xfffffff0;
	/*2147483647
		- 2147483648*/
	/*char str[16];
	_itoa_s(6.0, str, 16);
	cout << str;*/


	long maxL = 0x7fffffff,
		 minL = 0x80000000;
	
	unsigned long maxUL = 0xffffffff,
				  minUL = 0x00000000,
				  h = 0,y= 1;

	/*4294967295*/


	float s = 6.0, // 0x6
		  _s = -6.0; // 0xfffffffa

	double dou = 4.1,
		  _dou = -4.1;

	bool* Pval1 = &val1,
		*Pval2 = &val2;

	char* PsymbEN = &symbEN,
		* PsymbRU = &symbRU;

	wchar_t* psEN = &sEN,
		*psRU = &sRU;

	short *px = &x, 
		*p_x = &_x; 

	float* ps = &s, 
		*p_s = &_s; 

	double* pd = &dou,
		*p_d = &_dou;

	void (*foo)();

	foo = func;

	foo();

	float f1 = 52.2f;
	float inf = f1 / 0;
	float minusInf = (-f1) / 0;
	float ind = inf / minusInf;

	return 0;
}