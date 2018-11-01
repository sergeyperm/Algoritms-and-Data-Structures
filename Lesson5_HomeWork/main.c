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
T Queue[MaxN];
int front = 0;
int rear = 0;
int N = -1;


#pragma region Реализация очереди
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

#pragma endregion
#pragma region Реализация стека через массив
//Реализация стека через массив
void pushStack(T i)
{
	if (N < MaxN)
	{
		N++;
		Stack[N] = i;
	}
	else
		printf("Stack overflow");
}
T popStack()
{
	if (N != -1)
		return Stack[N--];
	else
		printf("Stack is empty");
}
void printStack()
{
	int i = N;
	if (i == -1)
	{
		printf("Stack is empty");
	}
	else
	{
		while (i != -1)
		{
			printf("%d ", Stack[i--]);
		}
	}
}
void clearStack()
{
	int i = N;
	if (i != -1)
	{
		while (i != -1)
		{
			popStack();
			i--;
		}

	}
}
#pragma endregion

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

//Реализация очереди через массив
void Enqueue(T i)
{
	if (rear < MaxN - 1)
	{
		Queue[rear] = i;
		rear++;
	}
	else printf("Queue is overflow!!");
}
T Dequeue()
{
	int x;
	if (checkEmptyQueue() == 1) printf("Queue is empty!!");
	x = Queue[front];
	front++;
	return x;
}
void printQueue()
{
	if (checkEmptyQueue() == 1) printf("Queue is empty!!");
	else
		for (int h = front; h < rear; h++)
		{
			printf("%d ", Queue[h]);
		}

}
int checkEmptyQueue()
{
	if (rear < front) return 1;
	else return 0;
}


//Стек на основе односвязного списка

struct TNode
{
	int value;
	struct Node* next;
};

typedef struct TNode Node;

struct TstackSpisok
{
	Node *head;
	int size;
	int maxsize;
};

typedef struct TstackSpisok stackSpisok;

void initstackSpisok(stackSpisok* stack)
{
	stack->head=NULL;
	stack->size = 0;
	stack->maxsize = MaxN;
}

void pushstackSpisok(stackSpisok* stack, T value)
{
	if (stack->size >= stack->maxsize)
	{
		printf("Stack size is overflow!!!");
	} 
		Node *tmp = (Node*)malloc(sizeof(Node));
		tmp->value = value;
		tmp->next = stack->head;
		stack->head = tmp;
		stack->size++;
}

T popstackSpisok(stackSpisok* stack)
{
	if (stack->size == 0)
	{
		printf("Stack is empty");
		return;
	}
	// Временный указатель
	Node* next = NULL;
	// Значение "наверху" списка
	T value;
	value = stack->head->value;
	next = stack->head;
	stack->head = stack->head->next;
	// Запись, на которую указывала голова удаляем, освобождая память
	free(next);
	// Возвращаем значение, которое было в голове
	stack->size--;
	return value;
}

void PrintStackSpisok(stackSpisok* stack)
{
	Node *current = stack->head;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
}


//Очередь с использованием односвязного списка

struct TNodeQ
{
	int value;
	struct NodeQ* next;
};
typedef struct TNode NodeQ;

struct TQueueSpisok
{
	NodeQ *front;
	NodeQ *rear;
	int size;
	int maxsize;
};

typedef struct TQueueSpisok queueSpisok;

void initqueueSpisok(queueSpisok* queue)
{
	queue->front = 0;
	queue->rear = 0;
	queue->size = 0;
	queue->maxsize = 1000;
}

void EnQueueSpisok(queueSpisok* queue, int value)
{
	if (queue->size >= queue->maxsize)
	{
		printf("Queue size is overflow!!!");
	}
	NodeQ *tmp = (NodeQ*)malloc(sizeof(NodeQ));
	tmp->value = value;
	tmp->next = NULL;
	if ((queue->size == 0)&&(queue->front==queue->rear))
	{
		queue->front = tmp;
		queue->rear = tmp;
		queue->size++;
	}
	else
	{
		queue->rear->next = tmp;
		queue->rear = tmp;
	}
	
	
}

int DeQueueSpisok(queueSpisok* queue)
{
	NodeQ *tmp = (NodeQ*)malloc(sizeof(NodeQ));
	if (queue->front)
	{
		tmp = queue->front->next;
		int value = queue->front->value;
		queue->front = tmp;
		/*free(tmp);*/
		return value;
	}
}




void printQueueSoisok(queueSpisok* queue)
{
	
	NodeQ *tmp = (NodeQ*)malloc(sizeof(NodeQ));
	tmp = queue->front;
	if (queue->front == NULL)
	{
		printf("Queue is empty");
	}
	else
	{
		while (tmp != NULL)
		{
			printf("%d ", tmp->value);
			tmp = tmp->next;
		}
	}

}


solution1()
{
	T c;
	printf("Convert to Bin Program\n");
	int number = 0;
	printf("Enter N:");
	scanf("%d", &number);

	while (number > 0)
	{
		pushStack(number % 2);
		number = number / 2;
	}
	printf("N in 10->N in 2: ");
	while (N != -1)
		printf("%d", popStack());
	printf("\n");
}
solution2()
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
			pushStack(myString[i]);
		}

		if ((myString[i] == ')') || (myString[i] == '}') || (myString[i] == ']') && N > 0)
		{
			if (myString[i] == popStack())
			{
				popStack();
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
}
solution5()
{
	printf("How stack work:\n");
	printf("Stack:");
	for (int i = 0; i <= 20; i++)
	{
		pushStack(i);
	}
	printStack();
	printf("\n");
	printf("------------------------------------\n");
	printf("Pop 1 element:");
	printf("\n");
	popStack();
	printf("Stack:");
	printStack();
	printf("\n");
	printf("Clear Stack:\n");
	clearStack();
	printf("Stack:");
	printStack();
	printf("\n");
	printf("------------------------------------\n");
}
solution6()
{
	printf("How Queue work:\n");
	printf("Queue:");
	for (int i = 0; i <= 20; i++)
	{
		Enqueue(i);
	}
	printQueue();
	printf("\n");
	printf("------------------------------------\n");
	printf("Deque front element:%d", Dequeue());
	printf("\n");
	printQueue();
	printf("------------------------------------\n");
	printf("Deque front element:%d", Dequeue());
	printf("\n");
	printQueue();
	for (int i = 0; i < 20; i++)
	{
		printf("Deque front element:%d", Dequeue());
		printf("\n");
	}
	printQueue();
	/*printf("Stack:");
	printStack();
	printf("\n");
	printf("Clear Stack:\n");
	clearStack();
	printf("Stack:");
	printStack();
	printf("\n");
	printf("------------------------------------\n");*/
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

solution7()
{
	stackSpisok myStack;
	initstackSpisok(&myStack);
	for (int i=0;i<15;i++) pushstackSpisok(&myStack, i);
	printf("STACK:\n");
	PrintStackSpisok(&myStack);
	printf("\n");
	for (int j = 0; j < 18; j++)
	{
		printf("Pop %d element:%d\n",j,popstackSpisok(&myStack));
	}
	PrintStackSpisok(&myStack);
	printf("\n");
}

solution8()
{
	queueSpisok myQueue;
	printf("How queueSpisok work:\n");
	printf("Intit queue\n");
	initqueueSpisok(&myQueue);
	printf("front: \n", myQueue.front);
	printf("front: \n", myQueue.rear);
	for (int i = 0; i < 15; i++) EnQueueSpisok(&myQueue, i);
	printf("Add ten digit in queue from 1 to 15\n");
	printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
    printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
	printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
	printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
	printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
	printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
	printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
	printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
	printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
	printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
	printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
	printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
	printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
	printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
	printQueueSoisok(&myQueue);
	printf("\n");
	printf("front:%d \n", myQueue.front->value);
	printf("rear:%d\n", myQueue.rear->value);
	printf("Pop 1 element from queue %d\n", DeQueueSpisok(&myQueue));
	printQueueSoisok(&myQueue);
	printf("\n");
	
}



void Menu()
{
	puts("==========================");
	printf("MENU\n");
	printf("1-Convert to Bin\n");  //Перевод числа из десятичной в двоичную систему
	printf("2-Check sequence\n");  /*Проверка скобочной последовательности*/
	printf("3-Queue\n");//Очередь
	printf("4-Dequeu\n");//Двусторонняя очередь 
	printf("5-Sтack\n");//Стек на массиве
	printf("6-Queue arrary\n");//Очередь на массиве
	printf("7-Stack spisok\n");//Стек на односвязном списке
	printf("8-Queue spisok\n");//Очередь на односвязном списке
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

