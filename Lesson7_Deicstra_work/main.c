#include "main.h"
#include "main.h"
#include "main.h"
#include "Main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 13
//#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS
const int N = 5;
const char* filename = "data.txt";
const int MaxInt = 20000000;

struct TNode
{
	int value;
	struct NodeQ* next;
	struct NodeQ* prev;
};
typedef struct TNode Node;

struct TDequeue
{
	Node *head;
	Node *tail;
	int size;
	int maxsize;
};

typedef struct TDequeue dequeue;


void initDequeue(dequeue* dq)
{

	dq->head = 0;
	dq->tail = 0;
	dq->size = 0;
	dq->maxsize = 10000;
}

int isEmptyDequeue(dequeue* dq)
{
	if ((dq->head == 0) && (dq->tail == 0))
		return 0;
	else return 1;
}

void addInfront(dequeue* dq, int value)
{
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	if (isEmptyDequeue(dq) == 0)
	{
		tmp->next = 0;
		tmp->prev = 0;
		dq->head = tmp;
		dq->tail = tmp;
	}
	else
	{
		tmp->next = dq->head;
		dq->head->prev = tmp;
		dq->head = tmp;
		dq->head->prev = 0;
	}
}

void addInBack(dequeue* dq, int value)
{
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	if (isEmptyDequeue(dq) == 0)
	{
		tmp->next = 0;
		tmp->prev = 0;

		dq->head = tmp;
		dq->tail = tmp;
	}
	else
	{
		tmp->prev = dq->tail;
		dq->tail->next = tmp;
		dq->tail = tmp;
		dq->tail->next = 0;
	}
}

int delHead(dequeue* dq)
{
	Node *tmp = (Node*)malloc(sizeof(Node));
	int value = dq->head->value;
	if (dq->head == dq->tail)
	{
		tmp = dq->head->next;
		dq->head = tmp;
		dq->tail = tmp;
	}
	else
	{
		tmp = dq->head->next;
		dq->head = tmp;

	}
	return value;
}

int delTail(dequeue* dq)
{
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp = dq->tail->prev;
	dq->tail = tmp;
}


void printDequeuFrontTail(dequeue* dq)
{
	if (isEmptyDequeue(dq) == 0)
	{
		printf("Dequeue is empty!!!");
	}
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp = dq->head;
	while (tmp != dq->tail->next)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}

}


//загрузка матрицы смежности из файла
int load(int W[SIZE][SIZE])
{
	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Can't open file");
		exit(1);
	}
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			int a;
			fscanf(file, "%d", &a);
			if (a == 0)
				W[i][j] = MaxInt;
			else
				W[i][j] = a;
		}
	fclose(file);
	return 0;
}
//печать матрицы смежности
int printMatrix(int G[SIZE][SIZE])
{
	printf("%s", " ");
	for (int i = 0; i < SIZE; i++)
		printf("%d", i, i);
	printf("\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d", i, i);
		for (int j = 0; j < SIZE; j++)
			printf("%3d", (G[i][j] == MaxInt) ? 0 : G[i][j]);
		printf("\n");
	}
	return 0;
}
int checkPeakStatus(int* W[SIZE])
{
	int result = 1;
	for (int i = 0; i < SIZE; i++)
	{
		if (W[i] < 2)
		{
			result = 0;
			break;

		}
	}

	return result;

}

printInfo(int* W[SIZE], int*G[SIZE])
{
	printf("Peak status:");
	for (int i = 0; i < SIZE; i++) printf("%d ", W[i]);
	printf("\n");
	printf("Routes:");
	for (int i = 0; i < SIZE; i++) printf("%d ", G[i]);
	printf("\n");
}


solution1()
{
	int W[SIZE][SIZE]; // Матрица смежности
	load(W);
	printMatrix(W);
	getchar();
	int startPeak = 0;
	int finishPeak = 0;
	printf("Enter start peak:");
	scanf("%d", &startPeak);
	printf("\n");
	printf("Enter finish peak:");
	scanf("%d", &finishPeak);
	printf("\n");
	int peakStatus[SIZE];//Массив состояний 0-неизвестная вершина, 1-известная вершина, 2-обработанная вершина
	int routes[SIZE];//Массив маршрутов
	dequeue myDequeue;
	initDequeue(&myDequeue);
	for (int i = 0; i < SIZE; i++) peakStatus[i] = 0;

	peakStatus[startPeak] = 1;
	addInfront(&myDequeue, startPeak);
	int currentPeak;
	routes[startPeak] = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (i != startPeak) routes[i] = 100000;
	}
	do
	{
		currentPeak = delHead(&myDequeue);
		if (peakStatus[currentPeak] == 1)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (W[currentPeak][j] != MaxInt)
				{
					if (peakStatus[j] == 0)
					{
						addInBack(&myDequeue, (int)j);
						peakStatus[j] = 1;
						if (routes[currentPeak] < routes[j])
						{
							routes[j] = W[currentPeak][j] + routes[currentPeak];
						}
					}
				}
			}
			peakStatus[currentPeak] = 2;
			printInfo(peakStatus, routes);

		}
	} while (checkPeakStatus(peakStatus) != 1);


	dequeue shortestway;
	initDequeue(&shortestway);
	addInfront(&shortestway, finishPeak);
	addInfront(&myDequeue, finishPeak);
	int peak;
	do
	{
		peak = delHead(&myDequeue);
		for (int j = 0; j < SIZE; j++)
		{

			if ((routes[peak] - W[peak][j]) == routes[j])
			{
				addInBack(&myDequeue, (int)j);
				addInfront(&shortestway, (int)j);
			}
		}

	} while (peak != startPeak);

	printf("Shortest way from %d to %d:", startPeak, finishPeak);
	printDequeuFrontTail(&shortestway);
	printf("\n");
}


void Menu()
{
	puts("==========================");
	printf("MENU\n");
	printf("1-Algorithm Deicstra\n");  //Алгоритм Дейкстра
	puts("==========================");
	printf("Insert number solution of tasks Lesson 7:");
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
