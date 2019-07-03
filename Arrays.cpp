#include"Arrays.h"

Arrays::Arrays()
{
	//������� ����� F2, ���� ��� ���� �����-�� ������
	ofstream out("F2.txt", ios::out);
	out.close();
	//

	ifstream ipf;
	ipf.open("F1.txt", ios::in);


	if (ipf.is_open())
	{
		//��������� ���������� ����� �������� �� 1 �� 10
		srand(time(NULL));
		size = (rand() % 10) + 1;
		//��������� ������ ��� �������
		arr = new int *[size];

		for (int i = 0; i < size; i++)
		{
			*(arr + i) = new int[5];
		}

		// ����������� ������ �� ����� � �������
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
					cout << "������� �� 0!!!" << endl << "������ �������" << i << "-�� ������, " << j << "-��� ������� ��������� ������� �� ����� F1 ����� 0" << endl << "�������� ����� ��������� �� 1!!!!" << endl;
					system("pause");
					*(*(arr + i) + j) += 1;
				}
			}
		}

		ipf.close();
	}
	else
	{
		cout << "���� F1 �� ������� �������!!!!" << endl;
		system("pause");
	}
}

Arrays::~Arrays()
{
	//������������ ������
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