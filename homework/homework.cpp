/*Дана квадратная матрица А
порядка n и натуральное число m. По матрице построить вектор B
размерности m, где B i равно следу матрицы А i , здесь i=1, 2, … , m.
В программе описать следующие функции:
- нахождение следа матрицы;
- умножение двух матриц;	
- построение вектора по матрице.*/
#include <iostream>
using namespace std;

int** memory(int n, int m);
void fill(int** a, int n, int m);
int trace(int** A, int n);
int sp(int* arr1, int* arr2, int n);
int** matrix_p(int** A, int** B, int n);
int* vector(int** A, int n, int m);

int main()
{
	setlocale(LC_ALL, "Russian");
	int n,m;
	printf("Введите размерность\n");
	scanf_s("%d", &n);
	int** A = memory(n, n);
	fill(A, n, n);
	printf("Введите m\n");
	scanf_s("%d", &m);
	int* ans = vector(A, n, m);
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
	for (int i = 0; i <= n; i++)
	{
		trace += A[i][i];
	}
	return trace;
}
//скалярное произверение
int sp(int* arr1, int* arr2, int n)
{
	int sp = 0;
	for (int i = 0; i < n; i++)
	{
		sp = sp + (arr1[i] * arr2[i]);
	}
	return sp;
}
//конвертер столбца в массив
int* mas(int** A, int j, int n)
{
	int* ans = new int[n];
	for (int i = 0; i < n; i++)
	{
		ans[i] = A[i][j];
	}
	return ans;
}
//умножение матриц
int** matrix_p(int** A, int** B, int n)
{
	int** ans = memory(n, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int* temp = mas(B, j,n);
			ans[i][j] = sp(A[i], temp, n);
			delete temp;
		}
	}
	return ans;
}
//построение вектора по матрице
int* vector(int** A, int n, int m)
{
	int* ans = new int[m];
	for (int i = 0; i < m; i++)
	{
		ans[i] = trace(A, i);
	}
	return ans;
}