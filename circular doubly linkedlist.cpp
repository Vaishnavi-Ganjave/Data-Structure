

                                          //CIRCULAR DOUBLY LINKEDLIST

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	struct node* prev;
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
		printf("memory not allocated \n");
	}
	else
	{
		printf("enter a value: ");
		scanf("%d",&value);

		newnode -> prev = NULL;
		newnode -> data = value;
		newnode -> next = NULL;
	}
	return newnode;
}

void createlinkedlist(struct node** tail)
{
	struct node* newnode = NULL;
	newnode = createnode();
	if(*tail == NULL)
	{
		*tail = newnode;
		(*tail) -> prev = newnode;
		(*tail) -> next = newnode;
	}
	else
	{
		newnode -> next = (*tail) -> next;
		(*tail) -> next = newnode;
		newnode -> prev = *tail;
		*tail = newnode;
	}
}

void display(struct node* tail)
{
	struct node* tempnode = tail -> next;
	if(tail == NULL)
	{
		printf("linked list is empty \n");
	}
	else
	{
		do
		{
			printf("%d => ",tempnode -> data);
			tempnode = tempnode -> next;
		}while(tail -> next != tempnode);
	      printf("\n");
	}
}

void insertatfirst(struct node** tail)
{
	struct node* newnode = NULL;
	newnode = createnode();
	if(*tail == NULL)
	{
		printf("linked list is empty \n");
	}
	else
	{
		newnode -> next = (*tail) -> next;
		(*tail) -> next = newnode;
		newnode -> prev = *tail;
	}
}

void insertatposition(struct node** tail)
{
	struct node* newnode = NULL;
	struct node* tempnode = (*tail) -> next;

	newnode = createnode();
	while(tempnode != *tail)
	{
		if(tempnode -> data == newnode -> data)
		{
			newnode -> next = tempnode -> next;
			tempnode -> next = newnode;
			newnode -> prev = tempnode;
			tempnode = tempnode -> next;
			newnode -> next -> prev = newnode;
		}
		tempnode = tempnode -> next;
	}
}

void main()
{
	int choice;
	struct node* last = NULL;
	do
	{
		printf("1. createlinkedlist \n");
		printf("2. displaylinkedlist \n");
		printf("3. insertatfirst \n");
		printf("4. insertatlast \n");
		printf("5. insertatposition \n");
		printf("0. exit \n");
		printf("enter your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 : createlinkedlist(&last);
				     break;
			case 2 : display(last);
			        break;
			case 3: insertatfirst(&last);
				     break;
			case 4 : createlinkedlist(&last);
				     break;
			case 5 : insertatposition(&last);
				     break;
			case 0 : printf("thank you");
			         break;
			default : printf("invalid choice \n");
				      break;
		}
	}while(choice != 0);
	getch();
}