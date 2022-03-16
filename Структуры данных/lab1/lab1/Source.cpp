#include <iostream>
#include <ctime>
using namespace std;

//����������� ���������� ����������� ����� �� ����� N - ����� ������������������ ���������.����������� 2 ������� �������� : ����������� ��������; �������� ��������.
//
//1. ������������ ������ ����� N.
//
//2. ��������� ����� ��������� ������.
//
//3. ����� ����� ��������� ����� ��������.
//
//4. ������� �� ����� ������������ N - �� ����� ���� ���������.
//
//5. ������� ����� ���������� ���������� ������ �������� ������� : ��������� ����� ������ �� ����� YY ������.
//
//6. ������� ����� ���������� ���������� ������ �������� ������� : ��������� ����� ��������� �� ����� YY ������.
//
//7. �������� �������� �������� ���������� ��� ������ N.��������� ������� ���������� �� ������� ������� ���������.

void rekurs(short, int, double*);

int main()
{
	setlocale(LC_ALL, "ru");

	int startTime,
		endTime;

	short N;

	cout << "������� ����� ������������������: ";
	cin >> N;

	if (N < 2)
		N = 2;

	double* FibonachyNums = new double[N];
	cout << "�������� ������:\n";

	FibonachyNums[0] = 0;
	FibonachyNums[1] = 1;

	cout << FibonachyNums[0] << ";\t" << FibonachyNums[1] <<";\t";

	startTime = clock();
	for (int i = 2; i < N; i++)
	{
		if (i % 8 == 0)
			cout << endl;

		FibonachyNums[i] = FibonachyNums[i - 1] + FibonachyNums[i - 2];

		cout << FibonachyNums[i] << ";\t";

	}
	endTime = clock();

	cout << "\n�������� ������ ����� " << -startTime + endTime << " ������������!" << endl;

	int diffLin = endTime - startTime;

	cout << "\n����������� �����:\n";

	cout << FibonachyNums[0] << ";\t" << FibonachyNums[1] << ";\t";

	startTime = clock();
	rekurs(N, 2, FibonachyNums);
	endTime = clock();

	cout << "\n����������� ������ ����� " << -startTime + endTime << " ������������!" << endl;

	int diffRekurs = endTime - startTime;

	delete[] FibonachyNums;

	cout << "\n\n����� �������� = 0" << diffRekurs / 1000 / 60 << ":0" << (diffRekurs / 1000) % 60 << ":" << diffRekurs % 1000
		<< "\n������� ��������� ������� = 0" << diffLin / 1000 / 60 << ":0" << (diffLin / 1000) % 60 << ":" << diffLin % 1000 << endl;

	return 0;

}

void rekurs(short N, int i, double* arr)
{
	if (i % 8 == 0)
		cout << endl;

	arr[i] = arr[i - 1] + arr[i - 2];

	cout << arr[i++] << ";\t";

	if (N != i)
		rekurs(N, i, arr);
}