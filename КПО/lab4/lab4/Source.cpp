﻿//

#include <iostream>
using namespace std;

int main()
{
	float R = 0,
		l = 0.1,
		d[] = { 0.89, 1.241, 1.02, 1.08, 1.231, 1.01 },
		Ri[] = {0.03, 0.06, 0.03, 0.03, 0.03, 0.04, 0.03},
		g = 9.8,
		p = 6900.0,
		t[] = {2.55, 1.8, 3.44, 3.19, 2.66, 3.32},
		n = 0,
		a;
	//for (int i = 0; i < 6; i++)
	//{
	//	a = d[i] * 0.001 * d[i] * 0.001 * g * p * t[i] / 18 / l;
	//	n += a;
	//	cout << a << endl;
	//	
	//}
	/*n /= 6;*/
	n = 1.07 * 0.001 * 1.07 * 0.001 * 6900.0 * 2.83 * g / 18 / l;
	cout << endl << n;
		
}