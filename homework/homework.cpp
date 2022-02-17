/*Дана квадратная матрица А
порядка n и натуральное число m. По матрице построить вектор B
размерности m, где B[i] равно следу матрицы А^i , здесь i=1, 2, … , m.
В программе описать следующие функции:
- нахождение следа матрицы;
- умножение двух матриц;	
- построение вектора по матрице.*/
#include <iostream>
using namespace std;

int** memory(int n, int m);
void fill(int** a, int n, int m);
int trace(int** A, int n);
int* vector(int** A,int** temp, int n, int m);
void fill_E(int** arr, int n);
void freeMemory(int** arr, int n);
int** matrix_p_fix(int** A, int** B, int n);

int main()
{
	setlocale(LC_ALL, "Russian");
	int n,m;
	printf("Введите размерность\n");
	scanf_s("%d", &n);
	int** A = memory(n, n);
	fill(A, n, n);
	int** temp = memory(n, n);
	fill_E(temp, n);
	printf("Введите m\n");
	scanf_s("%d", &m);
	int* ans = vector(A, temp, n, m);
	for (int i = 0; i < m; i++)
	{
		printf("%d ", ans[i]);
	}
	/*int** B = memory(n, n);
	fill(B, n, n);
	//тест умножения матриц
	int** C = matrix_p(A, B, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}*/
}
//выделение памяти
int** memory(int n, int m)
{
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	return a;
}
//заполнение элементов
void fill(int** a, int n, int m)
{
	printf("Заполните массив\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
}
//Вычисление следа матрицы
int trace(int** A, int n)
{
	int trace = 0;
	for (int i = 0; i < n; i++)
	{
		trace += A[i][i];
	}
	return trace;
}
//построение вектора по матрице
int* vector(int** A,int** temp, int n, int m)
{
	int* ans = new int[m];
	for (int i = 0; i < m; i++)
	{
		temp = matrix_p_fix(temp, A, n);
		ans[i] = trace(temp, n);
	}
	return ans;
}
//заполнение единичной матрицы
void fill_E(int** arr, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;

			if (i == j)
				arr[i][j] = 1;
		}
}
//Умножение матриц одной функцией
int** matrix_p_fix(int** A, int** B, int n)
{
	int** temp_m = memory(n, n);
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			for (int k = 0; k < n; k++)
			{
				temp += A[k][j] * B[i][k];
			}
			temp_m[i][j] = temp;
			temp = 0;
		}
	}
	freeMemory(A, n);
	return temp_m;
}
//освобождение памяти
void freeMemory(int** arr, int n)
{
	for (int i = 0; i < n; i++)
		delete[] arr[i];

	delete[] arr;
}