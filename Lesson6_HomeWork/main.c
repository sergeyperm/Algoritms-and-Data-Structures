
#include "main.h"
#include "Main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int T;
FILE* file;

typedef struct Node {
	T data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;




// Распечатка двоичного дерева в виде скобочной записи
void printTree(Node *root)
{
	if (root)
	{
		printf("%d", root->data);
		if (root->left || root->right)
		{
			printf("(");
			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");
			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

//Создание нового узла
Node* getFreeNode(T value, Node*parent)
{
	Node*tmp = (Node*)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

// Вставка узла 
void insert(Node **head, int value)
{
	Node *tmp = NULL;
	if (*head == NULL)
	{
		*head = getFreeNode(value, NULL); return;
	}
	tmp = *head;
	while (tmp)
	{
		if (value > tmp->data)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				continue;
			}
			else
			{
				tmp->right = getFreeNode(value, tmp);
				return;
			}
		}
		else if (value < tmp->data)
		{
			if (tmp->left)
			{
				tmp = tmp->left;
				continue;
			}
			else
			{
				tmp->left = getFreeNode(value, tmp);
				return;
			}
		}
		else
		{
			exit(2);
		}
	}
}

//Обход корень-левый-правый

void preOrderTraversRootLR(Node* root)
{
	if (root) {
		printf("%d ", root->data);
		preOrderTraversRootLR(root->left);
		preOrderTraversRootLR(root->right);
	}
}

//Обход левый-корень-правый
void preOrderTraversLRootR(Node* root)
{
	if (root) {
		preOrderTraversLRootR(root->left);
		printf("%d ", root->data);
		preOrderTraversRootLR(root->right);
	}
}


//Обход левый-правый-корень
void preOrderTraversLRRoot(Node* root)
{
	if (root) {
		preOrderTraversLRRoot(root->left);
		preOrderTraversLRRoot(root->right);
		printf("%d ", root->data);
	}
}


Node*Tree(int n)
{
	Node* newNode = NULL;
	int x, nl, nr;
	if (n == 0) newNode == NULL;
	else
	{
		fscanf(file, "%d", &x);
		nl = n / 2;
		nr = n - nl - 1;
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = x;
		newNode->left = Tree(nl);
		newNode->right = Tree(nr);
	}
	return newNode;
}



solution1()
{
	int hash = 0;
	char myString[100];
	printf("Enter string: ");
	scanf("%s", &myString);
	int i = 0;
	while (myString[i] != '\0')
	{
		hash += (int)myString[i];
		i++;
	}
	printf("hash=%d\n", hash);
}

Node *search(Node * root, int number)
{
	while (root)
	{
		if (root->data > number)
		{
			root = root->left;
			continue;
		}
		else if (root->data < number)
		{
			root = root->right;
			continue;
		}
		else {
			return root;
		}
	}
	return NULL;
}

solution2()
{
	Node *Tree = NULL;
	file = fopen("data.txt", "r");
	if (file == NULL)
	{
		puts("Can't open file!");
		exit(1);
	}
	int count;
	fscanf(file, "%d", &count); // Считываем количество записей
	int i;
	for (i = 0; i < count; i++)
	{
		int value;
		fscanf(file, "%d", &value);
		insert(&Tree, value);
	}
	fclose(file);
	printTree(Tree);
	printf("\nPreOrderTraversRootLR:");
	preOrderTraversRootLR(Tree);
	printf("\nPreOrderTraversLRootR:");
	preOrderTraversLRootR(Tree);
	printf("\nPreOrderTraversLRRoot:");
	preOrderTraversLRRoot(Tree);
	getchar();

}

solution3()
{
	Node *tree = NULL;
	file = fopen("data.txt", "r");
	if (file == NULL)
	{
		puts("Can't open file!");
		exit(1);
	}
	int count;
	fscanf(file, "%d", &count); // Считываем количество записей
	tree = Tree(count);
	fclose(file);
	printTree(tree);
	printf("\nPreOrderTraversRootLR:");
	preOrderTraversRootLR(tree);
	printf("\nPreOrderTraversLRootR:");
	preOrderTraversLRootR(tree);
	printf("\nPreOrderTraversLRRoot:");
	preOrderTraversLRRoot(tree);
	puts("\n");
	getchar();
}

//Поиск заданного элемента в дереве
solution4()
{
	Node *tree = NULL;
	Node *resultOfsearch; //переменная для передачи результата поиска в дереве
	file = fopen("data.txt", "r");
	if (file == NULL)
	{
		puts("Can't open file!");
		exit(1);
	}
	int count;
	fscanf(file, "%d", &count); // Считываем количество записей
	tree = Tree(count);
	fclose(file);
	printTree(tree);
	int number = 0;
	printf("\nEnter a number to search in tree:");
	scanf("%d", &number);
	resultOfsearch = search(tree, number);
	if (resultOfsearch != NULL)
		printf("Number in tree :-) Result of search:%d", resultOfsearch->data);
	else
		printf("Number not found in tree!!!");
	puts("\n");
	getchar();
}







void Menu()
{
	puts("==========================");
	printf("MENU\n");
	printf("1-HASCH\n");
	printf("2-Binary Tree\n");
	printf("3-Balanced Tree\n");
	printf("4-Search in Tree");
	printf("0-Exit\n");
	puts("==========================");
	printf("Insert number solution of tasks Lesson 6:");

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