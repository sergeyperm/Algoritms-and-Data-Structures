#include "main.h"
#include "Main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS
#define T int
#define MaxN 1000
T Stack[MaxN];

const int N = 5;
const char* filename = "data.txt";
const int MaxInt = 20000000;
int M = -1;

//Реализация  стека
void push(T i)
{
	if (M < MaxN)
	{
		M++;
		Stack[M] = i;
	}
	else
		printf("Stack overflow");
}
T pop()
{
	if (M != -1)
		return Stack[M--];
	else
		printf("Stack is empty");
}

//Реализация очереди
typedef struct node_t
{
	int value;
	struct node_t* next;
}  TNode;

typedef struct queue_t
{
	TNode* head;
	TNode* tail;
}  TQueue;

TQueue* Push(TQueue* queue, int value)
{
	TNode* node = malloc(sizeof(TNode));
	node->value = value;
	node->next = NULL;

	if (queue->head && queue->tail)
	{
		queue->tail->next = node;
		queue->tail = node;
	}
	else
	{
		queue->head = queue->tail = node;
	}

	return queue;
}

int Pop(TQueue* queue)
{
	int value = 0;

	if (queue->head)
	{
		value = queue->head->value;
		queue->head = queue->head->next;
	}

	return value;
}

void Clear(TQueue* queue)
{
	while (queue->head)
	{
		Pop(queue);
	}

	queue->head = queue->tail = NULL;
}

void Print(const TQueue* queue)
{
	const TNode* node = queue->head;

	for (; node; node = node->next)
	{
		printf("%d ", node->value);
	}
	printf("\n");
}

//реализация двусторонней офереди ДЕК

typedef struct deque
{
	int data[10]; //массив данных
	int last; //указатель на конец
}Deque;
void Creation(Deque *D) //создание дека
{
	D->last = 0;
}
int Full(Deque *D) //проверка дека на пустоту
{
	if (D->last == 0) return 0;
	else return 1;
}
void AddL(Deque *D, int value) //добавление элемента в начало
{
	if (D->last == 10)
	{
		printf("\nDek is FULL\n\n"); return;
	}

	for (int i = D->last; i > 0; i--)
		D->data[i] = D->data[i - 1];
	D->data[0] = value;
	D->last++;
}
void AddR(Deque *D, int value) //добавление элемента в конец
{
	if (D->last == 10)
	{
		printf("\nDek is Full\n\n"); return;
	}

	D->data[D->last++] = value;
}
void DeleteL(Deque *D) //удаление первого элемента
{
	for (int i = 0; i < D->last; i++) //смещение элементов
		D->data[i] = D->data[i + 1]; D->last--;
}
void DeleteR(Deque *D) //удаление последнего элемента
{
	D->last--;
}
int OutputL(Deque *D) //вывод первого элемента
{
	return D->data[0];
}
int OutputR(Deque *D) //вывод последнего элемента
{
	return D->data[D->last - 1];
}
int Size(Deque *D) //размер дека
{
	return D->last;
}
void PrintDeque(Deque* d)
{
	for (int j = 0; j < Size(d); j++)
		printf("%d ", d->data[j]);

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

solution1()
{
	int W[5][5]; // Матрица смежности
	load(W);
	printMatrix(W);
	getchar();
}

int checkpeakStatus(int peakStatus[5])
{
	int count = 0;
	for (int i = 0; i < 5; i++)
		if (peakStatus[i] == 3)
		{
			count++;
		}
	if (count == 5) return 1; else return 0;
}

solution2()
{
	int peaksStatus[5];//вспомогательный массив
	int W[5][5]; // Матрица смежности
	load(W);//выгрузка матрицы смежности
	Deque peaks;
	Creation(&peaks);
	for (int i = 0; i < 5; i++) peaksStatus[i] = 1;//заполнение 
	peaksStatus[0] = 2;
	AddL(&peaks, 0);
	int currentPeak;
	do
	{
		currentPeak = OutputL(&peaks);
		if (peaksStatus[currentPeak] == 2)
		{
			for (int j = 0; j < 5; j++)
			{
				if (W[currentPeak][j] != 0)
				{
					if (peaksStatus[j] == 1)
					{
						AddR(&peaks, j);
						peaksStatus[j] = 2;
					}
				}
			}
			peaksStatus[currentPeak] = 3;
		}
	} while (checkpeakStatus(peaksStatus) != 1);

	getchar();
}


void Menu()
{
	puts("==========================");
	printf("MENU\n");
	printf("1-ReadGraf from file\n");
	printf("2-The function of traversing the graph in width.\n");
	printf("0-Exit\n");
	puts("==========================");
	printf("Insert number solution of tasks Lesson 7:");
}


int main(int argc, char *argv[])

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
			/*case 4:
			{
				solution4();
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

	return 0;
}