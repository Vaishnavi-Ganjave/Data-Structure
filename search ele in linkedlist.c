
/*
Q1. Write c program to search a given element in given linked list
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

void search(struct node* head)
{
	int search;
	int flag = 0;
	printf("enter element to search: ");
	scanf("%d", &search);

	while(head != NULL)
	{
		if( search == head->data)
		{
			flag =1;
		}
		 head = head->next;
	}
    	if(flag == 1)
		printf("element found \n");
		else
	    printf("element is not found\n");
	
}

void main()
{
	int choice;
	struct node* first = NULL;

	printf("1. createlinkedlist()\n");
	printf("2. displaylinkedlist()\n");
	printf("3. search an element()\n");
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
		case 3: search(first);
			break;
		case 0: printf("THANK YOU\n");
			break;
		default: printf("invalid choice\n");
		}
	}
	while(choice != NULL);
	getch();
}
