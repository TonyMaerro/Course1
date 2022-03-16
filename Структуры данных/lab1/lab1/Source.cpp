#include <iostream>
#include <ctime>
using namespace std;

//Разработать приложение реализующие вывод на экран N - числа последовательности Фибоначчи.Реализовать 2 способа подсчета : рекурсивным способом; линейным способом.
//
//1. Пользователь вводит число N.
//
//2. Вычислить число Фибоначчи циклом.
//
//3. Найти число Фибоначчи через рекурсию.
//
//4. Вывести на экран пользователю N - ое число ряда Фибоначчи.
//
//5. Вывести время выполнения нахождения циклом согласно шаблону : Расчетное время циклом ХХ минут YY секунд.
//
//6. Вывести время выполнения нахождения циклом согласно шаблону : Расчетное время рекурсией ХХ минут YY секунд.
//
//7. Сравнить значение скорости выполнения для разных N.Объяснить разницу выполнения по времени разными способами.

void rekurs(short, int, double*);

int main()
{
	setlocale(LC_ALL, "ru");

	int startTime,
		endTime;

	short N;

	cout << "Введите длину последовательности: ";
	cin >> N;

	if (N < 2)
		N = 2;

	double* FibonachyNums = new double[N];
	cout << "Линейный способ:\n";

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

	cout << "\nЛинейный способ занял " << -startTime + endTime << " миллисекунды!" << endl;

	int diffLin = endTime - startTime;

	cout << "\nРекурсивный метод:\n";

	cout << FibonachyNums[0] << ";\t" << FibonachyNums[1] << ";\t";

	startTime = clock();
	rekurs(N, 2, FibonachyNums);
	endTime = clock();

	cout << "\nРекурсивный способ занял " << -startTime + endTime << " миллисекунды!" << endl;

	int diffRekurs = endTime - startTime;

	delete[] FibonachyNums;

	cout << "\n\nВремя рекурсии = 0" << diffRekurs / 1000 / 60 << ":0" << (diffRekurs / 1000) % 60 << ":" << diffRekurs % 1000
		<< "\nРазница линейного способа = 0" << diffLin / 1000 / 60 << ":0" << (diffLin / 1000) % 60 << ":" << diffLin % 1000 << endl;

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