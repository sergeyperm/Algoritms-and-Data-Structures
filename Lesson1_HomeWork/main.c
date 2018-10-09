#include "Main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS


//Помазкин Сергей
//1. Ввести вес и рост человека.Рассчитать и вывести индекс массы тела по формуле I = m / (h*h); где
//m - масса тела в килограммах, h - рост в метрах.
void solution1()
{
	int m = 0;
	float h = 0;
	float I = 0;
	printf("Body mass index calculation program: \n");
	puts(" ");
	printf("Enter body weight in kilograms:");
	scanf("%d", &m);
	printf("Enter height in meters:");
	scanf("%f", &h);
	I = m / (h*h);
	printf("Body mass index is %.2f \n", I);
	getchar();
	puts("==========================\n");
}

//2. Найти максимальное из четырех чисел.Массивы не использовать.

void solution2()
{
	int a, b, c, d;
	int max;
	printf("Maximum search program: \n");
	printf("Enter number a:");
	scanf("%d", &a);
	printf("Enter number b:");
	scanf("%d", &b);
	printf("Enter number c:");
	scanf("%d", &c);
	printf("Enter number d:");
	scanf("%d", &d);
	if ((a >= b) && (a >= c) && (a >= d))
	{
		max = a;
	}
	else if ((b >= c) && (b >= d))
	{
		max = b;
	}
	else if (c >= d)
	{
		max = c;
	}
	else
	{
		max = d;
	}
	printf("Maximum(%d,%d,%d,%d)=%d\n", a, b, c, d, max);
	puts("==========================\n");
}

//3.Написать программу обмена значениями двух целочисленных переменных :
//a.с использованием третьей переменной;
//b. *без использования третьей переменной.

void solution3()
{
	int a, b, c;
	printf("SWAP VARIABLES PROGRAM: \n");
	printf("Enter number a:");
	scanf("%d", &a);
	printf("Enter number b:");
	scanf("%d", &b);
	printf("Result of swap with third variable:");
	c = a;
	a = b;
	b = c;
	printf("a=%d; b=%d \n", a, b);
	printf("Result of swap without third variable:");
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a=%d; b=%d \n", a, b);
	puts("==========================\n");
}

void solution4()
{
	int a, b, c, d;
	float x1, x2;
	printf("THE ROOTS OF THE QUADRATIC EQUATION PROGRAM: \n");
	printf("Enter a:");
	scanf("%d", &a);
	printf("Enter b:");
	scanf("%d", &b);
	printf("Enter c:");
	scanf("%d", &c);
	d = b * b - 4 * a*c;
	if (d < 0) printf("quadratic equation has nor roots\n");
	if (d == 0)
	{
		x1 = (-b) / (2 * a);
		printf("quadratic equation has 1 root x=%.2f\n", x1);
	}
	if (d > 0)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
		printf("quadratic equation has 2 roots x1=%.2f; x2=%.2f\n", x1, x2);
	}
	puts("==========================\n");
}

//5. С клавиатуры вводится номер месяца.Требуется определить, к какому времени года он относится.
void solution5()
{
	int numberMonth;
	printf("SEASON BY NUMBER PROGRAM: \n");
	printf("Enter number of month:");
	scanf("%d", &numberMonth);
	switch (numberMonth)
	{
	case 1:
	case 2:
	case 12:
	{
		printf("Season of %d month is winter\n", numberMonth);
		break;
	}
	case 3:
	case 4:
	case 5:
	{
		printf("Season of %d month is spring\n", numberMonth);
		break;
	}
	case 6:
	case 7:
	case 8:
	{
		printf("Season of %d month is summer\n", numberMonth);
		break;
	}
	case 9:
	case 10:
	case 11:
	{
		printf("Season of %d month is autumn\n", numberMonth);
		break;
	}
	}
	puts("==========================\n");
}
//6. Ввести возраст человека(от 1 до 150 лет) и вывести его вместе с последующим словом «год»,
//«года» или «лет».
void solution6()
{

	char ageLET[256] = "let";
	char ageGODA[256] = "goda";
	char ageGOD[256] = "god";
	printf("AGE PROGRAM: \n");

	for (int i = 1; i <= 150; i++)
	{
		if (((i % 10 == 2) || (i % 10 == 3) || (i % 10 == 4)) && ((i % 100 != 12) && (i % 100 != 13) && (i % 100 != 14)))
		{
			printf("%d %s\n", i, ageGODA);

		}
		else if (i % 10 == 1 && i % 100 != 11)
		{
			printf("%d %s\n", i, ageGOD);
		}
		else
		{
			printf("%d %s\n", i, ageLET);
		}
	}
	puts("==========================\n");
}

//7. С клавиатуры вводятся числовые координаты двух полей шахматной доски(x1, y1, x2, y2).Требуется
//определить, относятся ли к поля к одному цвету или нет.
void solution7()
{
	int x1, x2, y1, y2;
	int flag1 = 1; //0-белый цвет, 1-черный
	int flag2 = 1;
	printf("EQUALS COLORS PROGRAM\n");
	printf("CHESSBOARD: \n");
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			if ((i % 2 != 0) ^ (j % 2 != 0))
			{
				printf("1 ");
			}
			else printf("0 ");
		}
		printf("\n");
	}
	printf("ENTER COORDINATES OF CHESSBOARD: \n");
	printf("Enter x1:");
	scanf("%d", &x1);
	printf("Enter y1:");
	scanf("%d", &y1);
	printf("Enter x2:");
	scanf("%d", &x2);
	printf("Enter y2:");
	scanf("%d", &y2);
	if ((x1 % 2 != 0) ^ (y1 % 2 != 0))
	{
		flag1 = 0;
	}
	if ((x2 % 2 != 0) ^ (y2 % 2 != 0))
	{
		flag2 = 0;
	}
	if (flag1 == flag2)
	{
		printf("Colors coordinates is equal!!\n");
	}
	else
		printf("Colors coordinates is NOT equal!!\n");
	puts("==========================\n");
}

//8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
void solution8()
{
	int a, b;
	printf("Square and cube numbers program\n");
	printf("Enter a:");
	scanf("%d", &a);
	printf("Enter b:");
	scanf("%d", &b);
	if (a < b)
	{
		while (a <= b)
		{
			printf("%d^2=%d %d^3=%d\n", a, a*a, a, a*a*a);
			a++;
		}
	}
	else
	{
		while (a >= b)
		{
			printf("%d^2=%d %d^3=%d\n", a, a*a, a, a*a*a);
			a--;
		}
	}

	puts("==========================\n");
}
//9. Даны целые положительные числа N и K.Используя только операции сложения и вычитания, найти
//частное от деления нацело N на K, а также остаток от этого деления.
void solution9()
{
	printf("Quotient and remainder of the division programm\n");
	int N, K;
	int tempN, tempK;
	int i = 0;
	printf("Enter N:");
	scanf("%d", &N);
	printf("Enter K:");
	scanf("%d", &K);
	tempN = N;
	tempK = K;
	while (tempN >= tempK)
	{
		tempN = tempN - K;
		i++;
	}
	printf("%d:%d=%d remainder %d\n", N, K, i, tempN);
	printf("Check standard functions\n");
	printf("%d:%d=%d remainder %d\n", N, K, N / K, N%K);
	puts("==========================\n");
}

//10. Дано целое число N(> 0).С помощью операций деления нацело и взятия остатка от деления
//определить, имеются ли в записи числа N нечетные цифры.Если имеются, то вывести True, если нет
//— вывести False.
void solution10()
{
	printf("Odd numbers programm\n");
	int N;
	int tempN;
	int i = 0;
	printf("Enter N:");
	scanf("%d", &N);
	tempN = N;
	int flag = 0;
	while (tempN > 0)
	{
		if (tempN % 2 != 0)
		{
			flag = 1;
			break;
		}
		else
		{
			tempN = tempN / 10;
		}
	}
	if (flag == 1)
	{
		printf("Number %d has odd numbers -TRUE\n", N);
	}
	else printf("Number %d has not odd numbers FALSE\n", N);

	puts("==========================\n");
}
//
//11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех
//положительных четных чисел, оканчивающихся на 8.
void solution11()
{
	printf("\n");
	printf("Arithmetic mean of all positive even numbers progrmas\n");
	int N = -1;
	int sum = 0;
	int i = 0;
	do
	{
		printf("Enter N:");
		scanf("%d", &N);
		if (N > 0 && N % 10 == 8)
		{
			sum = sum + N;
			i++;
		}
	} while (N != 0);
	printf("Avarege all positive even numbers=%.2f\n", (float)sum / i);
	puts("==========================\n");
}

void solution12()
{
	int a, b, c;
	printf("Find maximus of 3 numbers program: \n");
	printf("Enter a:");
	scanf("%d", &a);
	printf("Enter b:");
	scanf("%d", &b);
	printf("Enter c:");
	scanf("%d", &c);
	printf("Max(%d,%d,%d)=%d\n", a, b, c, (a >= b && a >= c) ? a : ((b >= c) ? b : c));
	puts("==========================\n");
}

void solution13()
{
	printf("random number = %d\n", rand() % 100);
	puts("==========================\n");
}






void Menu()
{
	puts("==========================");
	printf("MENU\n");
	printf("1-Body mass index \n");  /*Индекс массы тела*/
	printf("2-Maximum of four numbers \n"); /*Максимальное из четырех чисел*/
	printf("3-Exchange of variables \n");/*Обмен переменных 2 способа*/
	printf("4-The roots of the quadratic equation \n"); /*Корни квадратного уравнения*/
	printf("5-Season \n"); /*Время года*/
	printf("6-AGE \n"); /*Возраст человека*/
	printf("7-Numeric coordinates of the two fields of the chessboard \n"); /*Числовые координаты шахматной доски*/
	printf("8-Square and cube numbers \n"); /*Квадрат и куб числа*/
	printf("9-Quotient and remainder of the division \n"); /*Частное и остаток от деления*/
	printf("10-Odd numbers \n"); /*Нечетные цифры*/
	printf("11-Arithmetic mean of all positive even numbers \n"); /*Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8*/
	printf("12-The maximum of three numbers \n"); /*Написать функцию нахождения максимального из трех чисел.*/
	printf("13-Random numbers \n");/*Случайные цифры*/
	printf("14-Automorphic numbers \n");/*Автоморфные числа*/
	printf("0-Exit\n");
	puts("==========================");
	printf("Insert number solution of homework Lesson 1:");
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
			case 5:
			{
				solution5();
				break;
			}
			case 6:
			{
				solution6();
				break;
			}
			case 7:
			{
				solution7();
				break;
			}
			case 8:
			{
				solution8();
				break;
			}
			case 9:
			{
				solution9();
				break;
			}
			case 10:
			{
				solution10();
				break;
			}
			case 11:
			{
				solution11();
				break;
			}
			case 12:
			{
				solution12();
				break;
			}
			case 13:
			{
				solution13();
				break;
			}
			/*case 14:
			{
				solution14();
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

	} while (numberSolution != 0);

	getchar();
	getchar();
	getchar();
	return 0;


}