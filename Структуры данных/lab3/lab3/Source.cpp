#include <iostream>
#include <ctime>
#include "check.h"
using namespace std;

void sortMethodPuz(int*, int);
void sortMethodShella(int*, int);
void sortMethodSelection(int*, int);
void quickSort(int* arr, int first, int last);
void outArr(int*, int, int i = 0);

int main()
{
	setlocale(LC_ALL, "ru");
	int N,
		start,
		end,
		timePuz,
		timeShella,
		timeSel,
		timeFast;
	char maskN[40];

	cout << "Введит число элементов, которые будут в массиве:\t";
	cin.getline(maskN, 40);
	
	while (!isProved(maskN, 1, 2000000))
	{
		cls;
		cout << "Введит число элементов, которые будут в массиве:\t";
		cin.getline(maskN, 40);
	}
	cls;

	N = atoi(maskN);

	int* A = new int[N],
		* B = new int[N],
		* C = new int[N],
		* D = new int[N],
		* E = new int[N];

	cout << "Массив А состоит из:\t";
	for (int i = 0, num; i < N; i++)
	{
		num = rand() % 1000 - 100 + 1;
		A[i] = B[i] = C[i] = D[i] = E[i] = num;
	}
	outArr(A, N);
	
	ent;
	ent;

	cout << "Массив B(пузырек) состоит из:\t";
	start = clock();
	sortMethodPuz(B, N);
	end = clock();
	outArr(B, N);
	ent;
	timePuz = end - start;
	
	ent;
	ent;

	cout << "Массив С(вставка) состоит из:\t";
	start = clock();
	sortMethodShella(C, N);
	end = clock();
	outArr(C, N);
	ent;
	timeShella = end - start;

	ent;
	ent;

	cout << "Массив D(выбором) состоит из:\t";
	start = clock();
	sortMethodSelection(D, N);
	end = clock();
	outArr(D, N);
	ent;
	timeSel = end - start;

	ent;
	ent;

	cout << "Массив E(быстрая) состоит из:\t";
	start = clock();
	quickSort(E, 0, N - 1);
	end = clock();
	outArr(E, N);
	ent;
	timeFast = end - start;

	ent;
	ent;

	cout << "Метод пузырька занял в " << timePuz << " мс\n"
		<< "Метод вставки занял в " << timeShella << " мс\n"
		<< "Метод выбором занял в " << timeSel << " мс\n"
		<< "Быстрый метод занял в " << timeFast << " мс\n";

	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
}

void outArr(int* arr, int N, int i)
{
	if (i == N)
		return;
	cout << arr[i++] << ";\t";
	outArr(arr, N, i);
}
void sortMethodPuz(int* arr, int N)
{
	int num;
	bool isSorted = false;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			num = arr[i];
			arr[i] = arr[i + 1];
			isSorted = true;
			arr[i + 1] = num;		
		}
		if (N == i + 2)
		{
			if (!isSorted)
				break;
			else
			{
				isSorted = false;
				i = 0;
			}
		}
	}
}
void sortMethodShella(int* arr, int N)
{
	int num;
	for(int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			num = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = num;
		}
}
void sortMethodSelection(int* arr, int N)
{
	int num,
		max = 0;
	for (int i = N; i > 0; i--)
	{
		max = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[max] < arr[j])
				max = j;
		}
		num = arr[max];
		arr[max] = arr[i - 1];
		arr[i - 1] = num;
	}
}
void quickSort(int* arr, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = arr[(f + l) / 2]; 
	do
	{
		while (arr[f] < mid)
			f++;
		while (arr[l] > mid)
			l--;
		if (f <= l) 
		{
			count = arr[f];
			arr[f] = arr[l];
			arr[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quickSort(arr, first, l);
	if (f < last) quickSort(arr, f, last);
}