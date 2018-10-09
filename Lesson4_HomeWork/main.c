#include "Main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 5
#define M 5




void solution1()
{
	int A[7] = { 1,2,0,4,5,7,9 };  //Последовательность А
	int B[6] = { 1,3,5,6,7,2 };//Последовательность B
	int lcs = 0;//Длина максиальной подпоследовательности

	int lcsmatrix[8][7];           //Заполнение матрицы нулевыми значениями
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			lcsmatrix[i][j] = 0;
		}
	}
	printf("Sequences:\n");
	printf("A={ ");
	for (int i = 0; i < 7; i++) printf("%d", A[i]);
	printf("}\n");
	printf("B={ ");
	for (int i = 0; i < 6; i++) printf("%d", B[i]);
	printf("}\n");

	//Алгоритм поиска подпоследовательности и заполнения матрицы
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (A[i] == B[j])
			{
				lcsmatrix[i + 1][j + 1] = lcsmatrix[i][j] + 1;
				lcs = lcsmatrix[i][j] + 1;
			}

			else
			{
				lcsmatrix[i + 1][j + 1] = max(lcsmatrix[i + 1][j], lcsmatrix[i][j + 1]);
				lcs = max(lcsmatrix[i + 1][j], lcsmatrix[i][j + 1]);
			}
		}
	}

	printf("LCS=%d\n", lcs);

	//Вывод матрицы на экран
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			printf("%d ", lcsmatrix[i][j]);
		}
		puts("\n");
	}

	//Поиск подпоследовательности
	int res[10];
	int k = lcs;
	for (int i = 6, j = 5; i >= 0 && j >= 0;)
	{
		if (A[i] == B[j])
		{
			res[--k] = A[i];
			--i;
			--j;

		}
		else if (lcsmatrix[i + 1][j] > lcsmatrix[i][j + 1])
		{
			--j;
		}
		else
		{
			--i;
		}
	}
	/*Печать подпоследовательности*/
	printf("Greatest common subsequence:");
	for (int i = 0; i < lcs; i++) printf("%d", res[i]);
	puts("\n");
	getchar();


}

void Print2(int n, int m, int a[N][M])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}

void solution2()
{
	//Алгоритм из методички
//int A[N][M];
//int i, j;
//for (j = 0; j < M; j++)
//	A[0][j] = 1; // Первая строка заполнена единицами
//for (i = 1; i < N; i++)
//{
//	A[i][0] = 1;
//	for (j = 1; j < M; j++)
//		A[i][j] = A[i][j - 1] + A[i - 1][j];
//}
//Print2(N, M, A);
//Задание карты с запретными клетками
	int MAP[N][M];
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			MAP[i][j] = 1;
		}
	MAP[2][2] = 0;  //Задание барьера
	MAP[3][2] = 0; /*Задание барьера*/
	puts("Karta s zapretnyymi marshrutami:\n");
	Print2(N, M, MAP);
	int MAPROUTES[N][M]; //карта с количеством маршрутов
	//Анализ карты с барьерами и вычисление количества маршрутов
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if ((i == 0) || (j == 0)) MAPROUTES[i][j] = 1;
			else if (MAP[i][j] != 0)
			{
				MAPROUTES[i][j] = MAPROUTES[i - 1][j] + MAPROUTES[i][j - 1];
			}
			else (MAPROUTES[i][j] = 0);
		}
	puts("Map number of routes :\n");//Вывод на экран карты с количеством маршрутов с учтом барьеров
	Print2(N, M, MAPROUTES);
}

void Menu()
{
	puts("==========================");
	printf("MENU\n");
	printf("1-LCS\n");  /* Поиск наибольшей общей подпоследовательности*/
	printf("2-Number of routes\n");  /* Поиск наибольшей общей подпоследовательности*/

	printf("0-Exit\n");
	puts("==========================");
	printf("Insert number solution of tasks Lesson 4:");
}

int main()
{
	int number;

	do
	{
		Menu();

		if (scanf("%d", &number) != 1)
		{
			printf("ERROR! TRY AGAIN!\n");
			break;
		}
		else
		{
			puts("==========================");
			switch (number)
			{
			case 1:
			{
				solution1();
				break;
			}
			case 2:
			{
				solution2();
				break;
			}

			/*case 3:
			{
				solution3();
				break;
			}*/
			case 0:
			{
				printf("Bye! Bye!");
				break;
			}
			default:
				printf("Unknown change!!!\n");
				break;
			}
		}

	} while (number != 0);

	getchar();

	return 0;

}


