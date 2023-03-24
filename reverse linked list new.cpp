/*
Q4. Write c program to print given linked list in reverse order
Owner: Vaishnavi Ganjave
Batch: PPA9
*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* createnode()
{
	int value;
	struct node* newnode = NULL;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("memory not allocated\n");
	}
	else
	{
		printf("please enter a value\n");
		scanf("%d", &value);
		newnode->data = value;
		newnode->next = NULL;
	}
	return newnode;
}

void createlinkedlist(struct node** head)
{
	struct node* newnode = NULL;
	struct node* tempnode = *head;
	newnode = createnode();
	if(*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		while(tempnode->next != NULL)
		{
			tempnode = tempnode->next;
		}
		tempnode->next = newnode;
	}
}

void displaylinkedlist(struct node* head)
{
	while(head != NULL)
	{
		printf("%d=>", head->data);
		head = head->next;
	}
	printf("\n");
}


int countnode(struct node * head)
{
	int count = 0;
	while(head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}


void reverse(struct node* head)
{
	if(head->next == NULL)
	{
		printf("%d=>", head->data);
	}
	else
	{
		reverse(head->next);
		printf("%d=>", head->data);
	}
}

void main()
{
	int choice;
	struct node* first = NULL;

	printf("1. createlinkedlist()\n");
	printf("2. displaylinkedlist()\n");
	printf("3. reverse an linkedlist()\n");

	do
	{
	printf("please enter your choice\n");
	scanf("%d", &choice);

		switch(choice)
		{
		case 1: createlinkedlist(&first);
			break;
		case 2: displaylinkedlist(first);
			break;
		case 3: reverse(first);
			break;
		case 0: printf("THANK YOU\n");
			break;
		default: printf("invalid choice\n");
		}
	}
	while(choice != NULL);
	getch();
}






