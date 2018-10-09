#include "Main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LENGTH  1000
#define ARRAY_LENGTH1  10000



////Помазкин Сергей

//Создание массива
void createArray(int*arr, int length)
{
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		arr[i] = rand() % 100;
	}

}

//Вывод на экран массива
void printArray(int*arr, int length)
{
	for (int j = 0; j < length; j++)
	{
		printf("%d ", arr[j]);
	}
}

//Копирование массива в другой массив
void copyArray(int* arr, int* arr1, int length)
{
	for (int i = 0; i < length; i++)
	{
		arr1[i] = arr[i];
	}
}

//Сортировка пузырьком
int bubbleSort(int*arr, int length)
{
	int t = 0;
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			count++;
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				count++;
			}
		}
	}
	return count;
}
//Сорировка пузырьком оптимизированная. Сортировка прекращается если операции по перестановке оставщейся части массива не происходили при очередном шаге.
int optimBubbleSort(int*arr, int length)
{
	int t = 0;
	int count = 0;
	int innercount = 0;
	int flag = 0; //проверка произведенных перестановок
	for (int i = 0; i < length; i++)
	{
		if (flag != 0)
		{
			break;
		}
		else
		{
			innercount = 0;
			for (int j = 0; j < length - 1; j++)
			{
				count++;
				if (arr[j] > arr[j + 1])
				{

					innercount++;            //увеличиваем счетчик внутренний счетчик при не обходимости выполнять перестановку
					t = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = t;
					count++;
				}
			}
			if (innercount != 0)
			{
				flag = 0;
			}
			else flag = 1;//анализ количества операций по перестановке(всплытию). Если операций не было считается что дальше не имеет смысла продолжать сортировку, т.к. оставщаяся часть массива отсортирована
		}
	}
	return count;
}

//Шейкерная сортировка
int shakeSort(int*arr, int length)
{
	int t = 0;
	int leftarr = 0; //левая граница массива
	int rightarr = length - 1; //правая граница массива
	int count = 0;//счетчик итераций
	while (leftarr < rightarr)
	{
		for (int j = leftarr; j < rightarr; j++)//движение слева направо
		{
			count++;
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				count++;
			}
		}
		rightarr--;
		for (int m = rightarr; m > leftarr; m--)//движение справо налево
		{
			count++;
			if (arr[m] < arr[m - 1])
			{
				t = arr[m];
				arr[m] = arr[m - 1];
				arr[m - 1] = t;
				count++;
			}
		}
		leftarr++;
	}
	return count;
}

//Оптимизация шейкерной сортировки
int optimShakeSort(int*arr, int length)
{
	int t = 0;
	int leftarr = 0; //левая граница массива
	int rightarr = length - 1; //правая граница массива
	int count = 0;//счетчик итераций
	int flag = 1;
	while ((leftarr < rightarr) && flag > 0)
	{
		flag = 0;
		for (int j = leftarr; j < rightarr; j++)//движение слева направо
		{
			count++;
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				count++;
				flag = 1;
			}
		}
		rightarr--;
		for (int m = rightarr; m > leftarr; m--)//движение справо налево
		{
			count++;
			if (arr[m] < arr[m - 1])
			{
				t = arr[m];
				arr[m] = arr[m - 1];
				arr[m - 1] = t;
				count++;
				flag = 1;
			}
		}
		leftarr++;
	}
	return count;
}


//Бинарный поиск
int binarySearch(int*arr, int length, int value)
{
	int L = 0;
	int R = length - 1;
	int m = L + (R - L) / 2;
	int count = 0;
	while ((L <= R) && (arr[m] != value))
	{
		count++;
		if (arr[m] < value)
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
		m = L + (R - L) / 2;
	}
	if (arr[m] == value)
	{

		printf("Value %d find!  position in array is %d\n", value, m + 1);
		printf("Count iterations of binary search=%d \n", count);
		return 1;
	}
	else
	{
		printf("Value not found!!!\n");
		printf("Count iterations of binary search=%d \n", count);
		return -1;
	}
}

//Линейный поиск
void lineSearch(int* arr, int length, int value)
{
	int k = 0;
	int count = 0;
	while ((k < ARRAY_LENGTH) && (arr[k] != value))
	{
		k++;
		count++;
	}
	if (k != ARRAY_LENGTH)
	{
		printf("Value %d finded!  position in array is %d\n", value, k + 1);
		printf("Count iterations of line search=%d\n", count);
	}
	else printf("Value not found!!!\n");

}
//Линейный поиск в массиве
void solution1()
{
	int a[ARRAY_LENGTH];
	int value = 0;
	createArray(a, ARRAY_LENGTH);
	printArray(a, ARRAY_LENGTH);
	puts("\n");
	printf("Find value: ");
	scanf("%d", &value);
	lineSearch(a, ARRAY_LENGTH, value);
	puts("\n");
	puts("==========================\n");
}
//Бинарный поиск в массиве
void solution2()
{
	int a[ARRAY_LENGTH];
	int value = 0;
	createArray(a, ARRAY_LENGTH);
	printArray(a, ARRAY_LENGTH);
	bubbleSort(a, ARRAY_LENGTH);
	puts("\n");
	printf("Find value: ");
	scanf("%d", &value);
	int result = binarySearch(a, ARRAY_LENGTH, value);
	if (result == 1)
	{
		printf("Value %d finded!!!\n", value);
	}
	else
	{
		printf("Value not found!!!\n");
	}
	puts("==========================\n");
}
//Сравнениене производительности линейного и бинарного поиска
void solution3()
{
	int a[ARRAY_LENGTH];
	int value = 0;
	createArray(a, ARRAY_LENGTH);
	printArray(a, ARRAY_LENGTH);
	puts("\n");
	printf("Find value: ");
	scanf("%d", &value);
	printf("Result of line search:\n");
	lineSearch(a, ARRAY_LENGTH, value);
	bubbleSort(a, ARRAY_LENGTH);
	printf("Result of binary search:\n");
	binarySearch(a, ARRAY_LENGTH, value);
	puts("==========================\n");
}
//Сортировка массива пузырьком
void solution4()
{
	int a[ARRAY_LENGTH];
	int count = 0;
	createArray(a, ARRAY_LENGTH);
	puts("\n");
	puts("Array before bubblesort \n");
	printArray(a, ARRAY_LENGTH);
	puts("\n");
	puts("Array after bubblesort \n");
	count = bubbleSort(a, ARRAY_LENGTH);
	printArray(a, ARRAY_LENGTH);
	puts("\n");
	printf("Count iterations of bubble sort = %d \n", count);
	puts("==========================\n");
}
//Оптимизация сортировки пузырьком
void solution5()
{
	int a[ARRAY_LENGTH];
	int count = 0;
	createArray(a, ARRAY_LENGTH);
	puts("\n");
	puts("Array before optimization of bubble sort \n");
	printArray(a, ARRAY_LENGTH);
	count = optimBubbleSort(a, ARRAY_LENGTH);
	puts("\n");
	puts("Array after optimization of bubble sort \n");
	printArray(a, ARRAY_LENGTH);
	puts("\n");
	printf("Count iterations of optimization of bubble sort = %d \n", count);
	puts("==========================\n");
}
//Сравнение производительности сортировки пузырьком и оптимизированной сортировки пузырьком
void solution6()
{
	int countIterationsBubblesort[10];
	int countIterationsBubblesortOptim[10];
	for (int k = 0; k <= 5; k++)
	{
		int a[ARRAY_LENGTH];
		createArray(a, ARRAY_LENGTH);
		int a1[ARRAY_LENGTH];
		int a2[ARRAY_LENGTH];
		copyArray(a, a1, ARRAY_LENGTH);
		copyArray(a, a2, ARRAY_LENGTH);
		printf("TEST N %d\n", k + 1);
		puts("Array a before bubble sort \n");
		printArray(a, ARRAY_LENGTH);
		puts("\n");
		puts("Array a1 before bubble sort \n");
		printArray(a1, ARRAY_LENGTH);
		puts("\n");
		puts("Array a2 before bubble sort \n");
		printArray(a2, ARRAY_LENGTH);
		puts("\n");
		countIterationsBubblesort[k] = bubbleSort(a1, ARRAY_LENGTH);
		countIterationsBubblesortOptim[k] = optimBubbleSort(a2, ARRAY_LENGTH);
		puts("Array a1 after bubble sort \n");
		printArray(a1, ARRAY_LENGTH);
		puts("\n");
		puts("Array a1 after optimisation of bubble sort \n");
		printArray(a2, ARRAY_LENGTH);
		puts("\n");
		puts("==========================================");
	}

	int sum1 = 0;
	int sum2 = 0;
	printf("TEST N         1    2    3    4    5\n");
	printf("---------------------------------------\n");
	printf("Count BS     :");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", countIterationsBubblesort[j]);
		sum1 += countIterationsBubblesort[j];
	}
	puts("\n");
	printf("Count BSoptim:");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", countIterationsBubblesortOptim[j]);
		sum2 += countIterationsBubblesortOptim[j];
	}
	puts("\n");
	printf("Average value BS     =%4d\n", sum1 / 5);
	printf("Average value BSoptim=%4d\n", sum2 / 5);
}
//Задача №2 Реализация шейкерной сортировки.
void solution7()
{
	int a[ARRAY_LENGTH];
	int count = 0;
	createArray(a, ARRAY_LENGTH);
	puts("\n");
	puts("Array before shakesort \n");
	printArray(a, ARRAY_LENGTH);
	count = shakeSort(a, ARRAY_LENGTH);
	puts("\n");
	puts("Array after shakesort \n");
	printArray(a, ARRAY_LENGTH);
	puts("\n");
	printf("Count iterations of shakesort = %d \n", count);
	puts("==========================\n");
}
//Оптимизация шейкерной сортировки
void solution8()
{
	int a[ARRAY_LENGTH];
	int count = 0;
	createArray(a, ARRAY_LENGTH);
	puts("\n");
	puts("Array before optimisation of shakesort \n");
	printArray(a, ARRAY_LENGTH);
	count = optimShakeSort(a, ARRAY_LENGTH);
	puts("\n");
	puts("Array after optimisation of shakesort \n");
	printArray(a, ARRAY_LENGTH);
	puts("\n");
	printf("Count iterations of optimisation shakesort = %d \n", count);
	puts("==========================\n");
}
//Сраввнение производительности программ шейкерной сортировки оптимизированной и неоптимизированной
void solution9()
{
	int countIterationsShakesort[10];
	int countIterationsShakesortOptim[10];
	for (int k = 0; k <= 5; k++)
	{
		int a[ARRAY_LENGTH];
		createArray(a, ARRAY_LENGTH);
		int a1[ARRAY_LENGTH];
		int a2[ARRAY_LENGTH];
		copyArray(a, a1, ARRAY_LENGTH);
		copyArray(a, a2, ARRAY_LENGTH);
		printf("TEST N %d\n", k + 1);
		puts("Array a before shake sort \n");
		printArray(a, ARRAY_LENGTH);
		puts("\n");
		puts("Array a1 before shake sort \n");
		printArray(a1, ARRAY_LENGTH);
		puts("\n");
		puts("Array a2 before shake sort \n");
		printArray(a2, ARRAY_LENGTH);
		puts("\n");
		countIterationsShakesort[k] = shakeSort(a1, ARRAY_LENGTH);
		countIterationsShakesortOptim[k] = optimShakeSort(a2, ARRAY_LENGTH);
		puts("Array a1 after shake sort \n");
		printArray(a1, ARRAY_LENGTH);
		puts("\n");
		puts("Array a1 after optimisation of shake sort \n");
		printArray(a2, ARRAY_LENGTH);
		puts("\n");
		puts("==========================================");
	}

	int sum1 = 0;
	int sum2 = 0;
	printf("TEST N         1    2    3    4    5\n");
	printf("---------------------------------------\n");
	printf("Count SS     :");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", countIterationsShakesort[j]);
		sum1 += countIterationsShakesort[j];
	}
	puts("\n");
	printf("Count SSoptim:");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", countIterationsShakesortOptim[j]);
		sum2 += countIterationsShakesortOptim[j];
	}
	puts("\n");
	printf("Average value SS     =%4d\n", sum1 / 5);  // средннее значение производительности шейкерной сортировки
	printf("Average value SSoptim=%4d\n", sum2 / 5);   // средннее значение производительности оптимизированной шейкерной сортировки
}


//Тест программ шейкерной сортировки при количестве элементов 1000 
void testShakeSort()
{
	int countIterationsShakesort[10];
	int countIterationsShakesortOptim[10];
	for (int k = 0; k <= 5; k++)
	{
		int a[ARRAY_LENGTH];
		createArray(a, ARRAY_LENGTH);
		int a1[ARRAY_LENGTH];
		int a2[ARRAY_LENGTH];
		copyArray(a, a1, ARRAY_LENGTH);
		copyArray(a, a2, ARRAY_LENGTH);
		countIterationsShakesort[k] = shakeSort(a1, ARRAY_LENGTH);
		countIterationsShakesortOptim[k] = optimShakeSort(a2, ARRAY_LENGTH);
	}

	int sum1 = 0;
	int sum2 = 0;
	printf("ANALYSIS OF SHAKE SORT\n");
	printf("Array length=%d\n", ARRAY_LENGTH);
	printf("TEST N             1    2    3    4    5\n");
	printf("---------------------------------------\n");
	printf("O(N)\t       :");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", ARRAY_LENGTH*ARRAY_LENGTH);
	}
	puts("\n");
	printf("ShakeSort Norma:");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", countIterationsShakesort[j]);
		sum1 += countIterationsShakesort[j];
	}
	puts("\n");
	printf("ShakeSort Optim:");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", countIterationsShakesortOptim[j]);
		sum2 += countIterationsShakesortOptim[j];
	}
	puts("\n");
	float average1 = (float)sum1 / 5;
	float average2 = (float)sum2 / 5;
	printf("Average value ShakeSort Norma:=%4.0f\n", average1);  // средннее значение производительности шейкерной сортировки
	printf("Average value ShakeSort Optim:=%4.0f\n", average2);   // средннее значение производительности оптимизированной шейкерной сортировки
	puts("\n");
	printf("CONCLUTION:%s", average1 < average2 ? "Shake Sort Norma faster than Shake Sort Optim!!\n" : "Shake Sort Optim faster than Shake Sort Norma\n");
	printf("on %.2f pecents\n", (float)((1 - average2 / average1) * 100));
}

//Тест программ пузырьковой сортировки при количестве элементов 1000
void testBubbleSort()
{
	int countIterationsBubblesort[10];
	int countIterationsBubblesortOptim[10];
	for (int k = 0; k <= 5; k++)
	{
		int a[ARRAY_LENGTH];
		createArray(a, ARRAY_LENGTH);
		int a1[ARRAY_LENGTH];
		int a2[ARRAY_LENGTH];
		copyArray(a, a1, ARRAY_LENGTH);
		copyArray(a, a2, ARRAY_LENGTH);
		countIterationsBubblesort[k] = bubbleSort(a1, ARRAY_LENGTH);
		countIterationsBubblesortOptim[k] = optimBubbleSort(a2, ARRAY_LENGTH);
	}

	int sum1 = 0;
	int sum2 = 0;
	printf("ANALYSIS OF BUBBLE SORT\n");
	printf("Array length=%d\n", ARRAY_LENGTH);
	printf("TEST N             1    2    3    4    5\n");
	printf("---------------------------------------\n");
	printf("O(N)\t       :");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", ARRAY_LENGTH*ARRAY_LENGTH);
	}
	puts("\n");
	printf("BubbleSort Norma:");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", countIterationsBubblesort[j]);
		sum1 += countIterationsBubblesort[j];
	}
	puts("\n");
	printf("BubbleSort Optim:");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", countIterationsBubblesortOptim[j]);
		sum2 += countIterationsBubblesortOptim[j];
	}
	puts("\n");
	float average1 = (float)sum1 / 5;
	float average2 = (float)sum2 / 5;
	printf("Average value BubbleSort Norma:=%4.0f\n", average1);  // средннее значение производительности пузырьковой сортировки
	printf("Average value BubbleSort Optim:=%4.0f\n", average2);   // средннее значение производительности оптимизированной пузырьковой сортировки
	puts("\n");
	printf("CONCLUTION:%s", average1 < average2 ? "Bubble Sort Norma faster than Bubble Sort Optim!!\n" : "Bubble Sort Optim faster than Bubble Sort Norma\n");
	printf("on %.2f pecents\n", (float)((1 - average2 / average1) * 100));
}


//Тест программ шейкерной сортировки при количестве элементов 10000
void testShakeSort10000()
{
	int countIterationsShakesort[10];
	int countIterationsShakesortOptim[10];
	for (int k = 0; k <= 5; k++)
	{
		int a[ARRAY_LENGTH1];
		createArray(a, ARRAY_LENGTH1);
		int a1[ARRAY_LENGTH1];
		int a2[ARRAY_LENGTH1];
		copyArray(a, a1, ARRAY_LENGTH1);
		copyArray(a, a2, ARRAY_LENGTH1);
		countIterationsShakesort[k] = shakeSort(a1, ARRAY_LENGTH1);
		countIterationsShakesortOptim[k] = optimShakeSort(a2, ARRAY_LENGTH1);
	}

	int sum1 = 0;
	int sum2 = 0;
	printf("ANALYSIS OF SHAKE SORT\n");
	printf("Array length=%d\n", ARRAY_LENGTH1);
	printf("TEST N             1    2    3    4    5\n");
	printf("---------------------------------------\n");
	printf("O(N)\t       :");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", ARRAY_LENGTH1*ARRAY_LENGTH1);
	}
	puts("\n");
	printf("ShakeSort Norma:");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", countIterationsShakesort[j]);
		sum1 += countIterationsShakesort[j];
	}
	puts("\n");
	printf("ShakeSort Optim:");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", countIterationsShakesortOptim[j]);
		sum2 += countIterationsShakesortOptim[j];
	}
	puts("\n");
	float average1 = (float)sum1 / 5;
	float average2 = (float)sum2 / 5;
	printf("Average value ShakeSort Norma:=%4.0f\n", average1);  // средннее значение производительности шейкерной сортировки
	printf("Average value ShakeSort Optim:=%4.0f\n", average2);   // средннее значение производительности оптимизированной шейкерной сортировки
	puts("\n");
	printf("CONCLUTION:%s", average1 < average2 ? "Shake Sort Norma faster than Shake Sort Optim!!\n" : "Shake Sort Optim faster than Shake Sort Norma\n");
	printf("on %.2f pecents\n", (float)((1 - average2 / average1) * 100));
}

//Тест программ пузырьковой сортировки при количестве элементов 10000
void testBubbleSort10000()
{
	int countIterationsBubblesort[10];
	int countIterationsBubblesortOptim[10];
	for (int k = 0; k <= 5; k++)
	{
		int a[ARRAY_LENGTH1];
		createArray(a, ARRAY_LENGTH1);
		int a1[ARRAY_LENGTH1];
		int a2[ARRAY_LENGTH1];
		copyArray(a, a1, ARRAY_LENGTH1);
		copyArray(a, a2, ARRAY_LENGTH1);
		countIterationsBubblesort[k] = bubbleSort(a1, ARRAY_LENGTH1);
		countIterationsBubblesortOptim[k] = optimBubbleSort(a2, ARRAY_LENGTH1);
	}

	int sum1 = 0;
	int sum2 = 0;
	printf("ANALYSIS OF BUBBLE SORT\n");
	printf("Array length=%d\n", ARRAY_LENGTH1);
	printf("TEST N             1    2    3    4    5\n");
	printf("---------------------------------------\n");
	printf("O(N)\t       :");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", ARRAY_LENGTH1*ARRAY_LENGTH1);
	}
	puts("\n");
	printf("BubbleSort Norma:");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", countIterationsBubblesort[j]);
		sum1 += countIterationsBubblesort[j];
	}
	puts("\n");
	printf("BubbleSort Optim:");
	for (int j = 0; j < 5; j++)
	{
		printf("%4d ", countIterationsBubblesortOptim[j]);
		sum2 += countIterationsBubblesortOptim[j];
	}
	puts("\n");
	float average1 = (float)sum1 / 5;
	float average2 = (float)sum2 / 5;
	printf("Average value BubbleSort Norma:=%4.0f\n", average1);  // средннее значение производительности пузырьковой сортировки
	printf("Average value BubbleSort Optim:=%4.0f\n", average2);   // средннее значение производительности оптимизированной пузырьковой сортировки
	puts("\n");
	printf("CONCLUTION:%s", average1 < average2 ? "Bubble Sort Norma faster than Bubble Sort Optim!!\n" : "Bubble Sort Optim faster than Bubble Sort Norma\n");
	printf("on %.2f pecents\n", (float)((1 - average2 / average1) * 100));
}

//Сравнение разных видов сортировок
void solution10()
{
	testShakeSort();
	puts("---------------------------------");
	testBubbleSort();
	puts("---------------------------------");
	testShakeSort10000();
	puts("---------------------------------");
	testBubbleSort10000();

}



void Menu()
{
	puts("==========================");
	printf("MENU\n");
	printf("1-Line search \n");  /* Линейный поиск в массиве*/
	printf("2-Binary search \n");/*Бинарный поиск в отсортированном массиве*/
	printf("3-Compare Line search and Binary search \n"); /*Сравнение методов поиска*/
	printf("4-Bubble sort array \n"); /*Сортировка пузырьком*/
	printf("5-Optimization of bubble sort\n");/*Оптимизация пузырьковой сортировки*/
	printf("6-Compare bubblesorts programs\n");//Сравнение программ неоптимиз и оптимиз сортировок пузырьком
	printf("7-Shake sort\n");/*Шейкерная сортировка*/
	printf("8-Optimization of shake sort\n");/*Оптимизация шейкерной сортировки*/
	printf("9-Compare shake sort programs\n");/*Сравнение программ неоптимиз и оптимиз шейкерной сортировки*/
	printf("10-Comparison of the different types of sorting\n");/*Сравнение разных видов сортировок с асимптотической сложностью*/
	printf("0-Exit\n");
	puts("==========================");
	printf("Insert number solution of tasks Lesson 3:");
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
	getchar();
	getchar();
	return 0;
}