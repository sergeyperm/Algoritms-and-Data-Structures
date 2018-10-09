#include "main.h"
#include "Main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define T int
#define MaxN 1000
T Stack[MaxN];
int N = -1;
const M = 10;

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



//Реализация стека
void push(T i)
{
	if (N < MaxN)
	{
		N++;
		Stack[N] = i;
	}
	else
		printf("Stack overflow");
}
T pop()
{
	if (N != -1)
		return Stack[N--];
	else
		printf("Stack is empty");
}


//Реализация двусторонней очереди

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

solution4()
{
	Deque myDeque;
	Creation(&myDeque);
	for (int i = 0; i < 6; i++) AddL(&myDeque, i);
	AddR(&myDeque, 78);
	AddL(&myDeque, 3);
	PrintDeque(&myDeque);
}





void solution1()
{
	T c;
	printf("Convert to Bin Program\n");
	int number = 0;
	printf("Enter N:");
	scanf("%d", &number);

	while (number > 0)
	{
		push(number % 2);
		number = number / 2;
	}
	printf("N in 10->N in 2: ");
	while (N != -1)
		printf("%d", pop());
	printf("\n");
}

void solution2()
{
#define T char
	char myString[100];
	printf("Enter string: ");
	scanf("%s", &myString);
	int i = 0;
	while (myString[i] != '\0')
	{
		if ((myString[i] == '(') || (myString[i] == '{') || (myString[i] == '['))
		{
			push(myString[i]);
		}

		if ((myString[i] == ')') || (myString[i] == '}') || (myString[i] == ']') && N > 0)
		{
			if (myString[i] == pop())
			{
				pop();
			}
		}
		i++;
	}
	if (N >= 0) printf("Sequence is wrong"); else printf("Sequence is right");
	printf("\n");
}

solution3()
{
	TQueue myQueue = { NULL,NULL };
	printf("Queue\n");
	for (int i = 0; i < 10; i++) Push(&myQueue, i);

	Print(&myQueue);
	Pop(&myQueue);
	Print(&myQueue);
	printf("Queue after 5 Pop\n");
	Pop(&myQueue);
	Pop(&myQueue);
	Pop(&myQueue);
	Pop(&myQueue);
	Print(&myQueue);
	Clear(&myQueue);
	Print(&myQueue);
	printf("\n");
	printf("Stack\n");
	for (int i = 0; i < 10; i++) push(i);
	printf("%d ", pop());
	printf("%d ", pop());
	printf("%d ", pop());
	printf("%d ", pop());
	printf("\n");

}

void Menu()
{
	puts("==========================");
	printf("MENU\n");
	printf("1-Convert to Bin\n");  //Перевод числа из десятичной в двоичную систему
	printf("2-Check sequence\n");  /*Проверка скобочной последовательности*/
	printf("3-Queue");//Очередь
	printf("0-Exit\n");
	puts("==========================");
	printf("Insert number solution of tasks Lesson 5:");
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

