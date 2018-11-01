#include "main.h"
#include "Main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS




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
	if ((dq->head == 0) && (dq->tail==0)) 
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
		tmp->prev=dq->tail;
		dq->tail->next = tmp;
		dq->tail = tmp;
		dq->tail->next = 0;
	}
}

void delHead(dequeue* dq)
{
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp = dq->head->next;
	dq->head = tmp;
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

solution1()
{
	dequeue myDequeue;
	printf("How Dequeue work:\n");
	printf("Intit queue\n");
	initDequeue(&myDequeue);
	/*printf("front:%d \n", myDequeue.head->value);
	printf("tail:%d \n", myDequeue.tail->value);*/
	for (int i = 0; i < 15; i++) addInBack(&myDequeue, i);
	printf("Add front ten digit in dequeue from 1 to 15\n");
	printDequeuFrontTail(&myDequeue);
	printf("\n");
	printf("head: %d\n", myDequeue.head->value);
	printf("tail: %d\n", myDequeue.tail->value);
	addInBack(&myDequeue, 22);
	addInfront(&myDequeue, 33);
	printDequeuFrontTail(&myDequeue);
	printf("\n");
	printf("head: %d\n", myDequeue.head->value);
	printf("tail: %d\n", myDequeue.tail->value);
	delHead(&myDequeue);
	printDequeuFrontTail(&myDequeue);
	printf("\n");
	printf("head: %d\n", myDequeue.head->value);
	printf("tail: %d\n", myDequeue.tail->value);
	printf("\n");
	delTail(&myDequeue);
	delTail(&myDequeue);
	printDequeuFrontTail(&myDequeue);
	printf("\n");
	printf("head: %d\n", myDequeue.head->value);
	printf("tail: %d\n", myDequeue.tail->value);
	printf("\n");
	delHead(&myDequeue);
	printDequeuFrontTail(&myDequeue);
	printf("\n");
	printf("head: %d\n", myDequeue.head->value);
	printf("tail: %d\n", myDequeue.tail->value);
	printf("\n");
}
void Menu()
{
	puts("==========================");
	printf("MENU\n");
	printf("1-Dequeue\n");  //Дек на основе двусвязного списка
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