#include <iostream>
#include <functional>
using namespace std;

void main()
{
	string str1 = "Hello";
	string str2 = "World!";
	string str3 = [](string s1, string s2) {
		return s1 + " " + s2;
	}(str1, str2);
	cout << str3 << endl;
	string str = [](string s1, string s2)
	{
		if (s1.size() >= s2.size())
			return s1;
		else
			return s2;
	}(str1, str2);
	cout << str;
}