#include "Main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH 100

//1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя
//рекурсию.
int size = 0;

void convertToBin(int N, int* arr)
{
	if (N > 0)
	{
		arr[size++] = N % 2;
		N = N / 2;
		convertToBin(N, arr);
	}

}

void solution1()
{
	printf("Convert to Bin Program\n");
	int N = 0;
	size = 0;
	printf("Enter N:");
	scanf("%d", &N);
	int arr[ARRAY_LENGTH];
	convertToBin(N, arr);
	for (int j = size - 1; j >= 0; j--)
	{
		printf("%d ", arr[j]);
	}
	puts("\n");
	puts("==========================\n");

}
int Pow(int a, int b)
{
	return (b > 0) ? a * Pow(a, b - 1) : 1;
}

//2. Реализовать функцию возведения числа a в степень b :
//a.Без рекурсии.
//b.Рекурсивно.
//c. *Рекурсивно, используя свойство чётности степени.

void solution2()
{
	printf("POW(a,b) Program\n");
	int a, b = 0;
	int x = 0;
	int tempA;
	int tempB;
	int xt = 1;
	printf("Enter a:");
	scanf("%d", &a);
	printf("Enter b:");
	scanf("%d", &b);
	x = Pow(a, b);
	tempA = a;
	tempB = abs(b);
	printf("Pow(%d,%d)=%d\n", a, b, x);
	while (tempB >= 2)
	{
		tempA = tempA * a;
		tempB--;
	}
	if (b > 0)
	{
		printf("Pow(%d,%d)=%d\n", a, b, tempA);
	}
	else
	{
		double result = 1 / tempA;
		printf("Pow(%d,%d)=%f\n", a, b, result);
	}
	puts("\n");
	puts("==========================\n");

}

solution3()
{
	int N = 20; //число для которого ищется количество команд
	int arr[21]; // массив чисел
	arr[1] = 1;// 
	arr[2] = 1;
	for (int i = 3; i < N + 1; i++)  // составление таблицы для поиска количества команд заданного числа
	{
		if (i % 2 != 0) arr[i] = arr[i - 1];
		if (i % 2 == 0) arr[i] = arr[i - 1] + arr[i / 2];

	}
	printf("N:");
	for (int i = 3; i < N + 1; i++)
	{
		printf("%d ", i);
	}
	puts("\n");
	printf("K:");
	for (int i = 3; i < N + 1; i++)
	{
		printf("%d ", arr[i]);
	}

	puts("\n");

	printf("Count calculators commands(+1,*2) from 3 to 20=%d\n", arr[20]);
	puts("\n");
	puts("==========================\n");
}

int factorial(int n)
{
	if (n == 0 || n == 1) return 1;
	return n * factorial(n - 1);
}


solution4()
{
	int N;
	int K;
	printf("Enter count people:");
	scanf("%d", &N);
	printf("Enter count commands:");
	scanf("%d", &K);
	int count = factorial(N) / (factorial(K)*factorial(N - K)); /*Показать всевозможные разбиения группы из N человек на К команд*/
	puts("\n");
	printf("Count conmibations =%d", count);
	puts("\n");
	puts("==========================\n");
}

void Menu()
{
	puts("==========================");
	printf("MENU\n");
	printf("1-Convert to Bin \n");  /*Перевода чисел из десятичной системы в двоичную*/
	printf("2-Pow(a,b) \n"); /*Функцию возведения числа a в степень b*/
	printf("3-Calculation\n");/*калькулятор*/
	printf("4-Cominetirica\n"); /*Показать всевозможные разбиения группы из N человек на К команд*/
	printf("0-Exit\n");
	puts("==========================");
	printf("Insert number solution of homework Lesson 2:");
}

int main()
{
	int numberSolution;
	do
	{
		Menu();
		if (scanf("%d", &numberSolution) != 1)
		{
			printf("ERROR! TRY AGAIN!\n");
			break;
		}
		else
		{
			puts("==========================");
			switch (numberSolution)
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
			case 3:
			{
				solution3();
				break;
			}
			case 4:
			{
				solution4();
				break;
			}

			case 0:
			{
				printf("Bye! Bye!");
				break;
			}
			default:
				printf("Unknown change!!!\n");
				break;
			}
			/*printf("If you want again enter please 100 or 0 for exit:");
			scanf("%d", &numberSolution);
			if (numberSolution == 0) printf("Bye! Bye!");*/
		}

	} while (numberSolution != 0);
	getchar();
	getchar();
	getchar();
	return 0;
}
