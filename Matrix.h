#pragma once

#include<fstream>
#include<iomanip>
#include<iostream>

using namespace std;

class Matrix
{
	float Matr[5][5];

public:
	Matrix();
	~Matrix();

	Matrix &operator = (int *);
};