#pragma once

#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iostream>

using namespace std;

class Arrays
{
	int **arr;
	int size;

public:

	Arrays();
	~Arrays();

	int get_size();
	int **get_arr();

	int * operator[](int pos);

};