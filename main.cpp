#include<iostream>
#include"Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	Arrays A;
	Matrix *matr_p = new Matrix[A.get_size()];

	for (int i = A.get_size() - 1, j = 0; i >= 0 ; i--, j++)
	{
		*(matr_p + j) = A[i];
	}

	delete[] matr_p;

	return 0;
} 