#include "main.h"
#include "main.h"
#include "Main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
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
int load(int W[5][5])
{
	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Can't open file");
		exit(1);
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
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
int printMatrix(int G[5][5])
{
	printf("%s", " ");
	for (int i = 0; i < N; i++)
		printf("%5c(%d) ", 65 + i, i);
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		printf("%c(%d)", 65 + i, i);
		for (int j = 0; j < N; j++)
			printf("%3d", (G[i][j] == MaxInt) ? 0 : G[i][j]);
		printf("\n");
	}
	return 0;
}

printInfo(int* W[5])
{
	for (int i = 0; i < 5; i++) printf("%d", W[i]);
	printf("\n");
}


int checkPeakStatus(int* W[5])
{
	int result = 1;
	for (int i = 0; i < 5; i++)
	{
		if (W[i] < 3)
		{
			result = 0;
			break;
			
		}
	}
	
	return result;
	
}

solution1()
{
	dequeue myDequeue;
	initDequeue(&myDequeue);
	int W[5][5]; // Матрица смежности
	load(W);
	printMatrix(W);
	getchar();
	int peakStatus[5];
	for (int i = 0; i < 5; i++) peakStatus[i] = 1;
	peakStatus[0] = 2;
	addInfront(&myDequeue, 0);
	int currentPeak;
	do
	{
		currentPeak = delHead(&myDequeue);
		if (peakStatus[currentPeak] == 2)
		{
			for (int j = 0; j < 5; j++)
			{
				if (W[currentPeak][j] !=MaxInt)
				{
					if (peakStatus[j]==1)
					{
						addInBack(&myDequeue, (int)j);
						peakStatus[j] = 2;
					}
				}
			}
			peakStatus[currentPeak] = 3;
			printInfo(peakStatus);
			getchar();
		}
	} while (checkPeakStatus(peakStatus) != 1);

}



void Menu()
{
	puts("==========================");
	printf("MENU\n");
	printf("1-A graph in a width\n");  //Обход графа в ширину
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