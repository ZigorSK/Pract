#include"Matrix.h"

Matrix::Matrix()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			Matr[i][j] = 0;
}                  

Matrix::~Matrix()
{
	//������� � ���� F2
	ofstream out("F2.txt", ios::app);
	
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			out << setw(20) << Matr[i][j];
		}
		out << endl;
	}

	float sum_d = 0;

	for (int i = 0; i < 5; i++)
		sum_d += Matr[i][i];

	out <<"���� �������:" << sum_d << endl << endl << endl <<endl;

	out.close();
}

Matrix & Matrix::operator = (int * arr)
{
	int max_x, i, j;
	float *M = &Matr[0][0];

	_asm
	{
		//���������� ��������� ������� �������
		mov esi, arr
		mov eax, [esi]
		inc esi
		inc esi
		inc esi
		inc esi
		mov ecx, 4
	m0:
		cmp eax, [esi]
		jns k
		mov eax, [esi]
	k:  inc esi
		inc esi
		inc esi
		inc esi

		loop m0
		mov max_x, eax

		//���������� ��������� ���������� �������
		finit
		
		mov esi, arr//�������� � esi ��������� ����� arr
		mov ebx, M//�������� � edi ��������� ����� Matr
		mov  i, 0
		mov ecx, 5
	m1:
		push ecx
		mov  j, 0
		mov ecx, 5
		//
	m2:
		//���������� Yij �� ������� Yij = (max(Xi) - Xi)/ Xj(asm)
 		fild max_x
		mov ax, 4
		mul i//ax = i*4
		add esi, eax 
		fild [esi]
		sub esi, eax
		
		fsubp st(1), st//��������� � st1, st0 ���������
		mov ax, 4
		mul j//ax = i*4
		add esi, eax
		fild[esi]
		sub esi, eax
		fdivp st(1), st//����� st1 �� st ��������� � st(1), st0 ���������
		//fxch st(1)// ������ ������� st(1) anb st

		//edi+j*4+i*20
		mov edx, 5
		mov ax, 4
		mul j
		push eax
		mov ax, 20
		mul i
		pop edx
		add eax, edx
		add ebx, eax
		//
		fstp [ebx]
		sub ebx, eax
		inc j
		loop m2
		//
		pop ecx
		inc i
		loop m1
	}

	return *this;
}