#include"Arrays.h"

Arrays::Arrays()
{
	//Очистка файла F2, если там были какие-то данные
	ofstream out("F2.txt", ios::out);
	out.close();
	//

	ifstream ipf;
	ipf.open("F1.txt", ios::in);


	if (ipf.is_open())
	{
		//Генерация рандомного числа массивов от 1 до 10
		srand(time(NULL));
		size = (rand() % 10) + 1;
		//Выделение памяти под массивы
		arr = new int *[size];

		for (int i = 0; i < size; i++)
		{
			*(arr + i) = new int[5];
		}

		// Перемещение данных из файла в массивы
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				try
				{
					ipf >> *(*(arr + i) + j);

					if (*(*(arr + i) + j) == 0)
						throw(*(*(arr + i) + j));
				}
				catch(int)
				{
					cout << "Деление на 0!!!" << endl << "Данный элемент" << i << "-ой строки, " << j << "-ого столбца исходного массива из файла F1 Равен 0" << endl << "Значение будет увеличено на 1!!!!" << endl;
					system("pause");
					*(*(arr + i) + j) += 1;
				}
			}
		}

		ipf.close();
	}
	else
	{
		cout << "Файл F1 не удалось открыть!!!!" << endl;
		system("pause");
	}
}

Arrays::~Arrays()
{
	//Освобождение памяти
	for (int i = 0; i < size; i++)
	{
		delete[] * (arr + i);
	}

	delete[] arr;
}

int Arrays::get_size()
{
	return size;
}

int ** Arrays::get_arr()
{
	return arr;
}

int * Arrays::operator[](int pos)
{
	return *(arr + pos);
}