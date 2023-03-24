
/* 
Que: implementation of queue using linked list
Owner: Vaishnavi Ganjave
Batch: PPA9
*/

//solution:


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct queue
{
	int data;
	struct queue* next;
};


struct queue* createnode()
{
	struct queue* newnode = NULL;
	int value;
	newnode = (struct queue*)malloc(sizeof(struct queue));
	if(newnode == NULL)
	{
		printf("Memory not allocated\n");
	}
	else
	{
		printf("Enter the value\n");
		scanf("%d",&value);
		newnode -> data = value;
		newnode -> next = NULL;
	}
	return newnode;
}


void Insert(struct queue** rear, struct queue** front)
{
	struct queue* newnode = NULL;
	struct queue* tempnode = *rear;
	newnode = createnode();
	if(*rear== NULL)
	{
		*rear = newnode;
		*front = newnode;
	}
	else
	{
	   (*rear) -> next = newnode;
	   *rear = newnode;
	}
}


void delete(struct queue** rear,struct queue** front)
{
	int n;
	struct queue* tempnode = NULL;
	if(*front == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		n = (*front) -> data;
		tempnode = *front;
		*front = (*front) -> next;
		free(tempnode);
		printf("Element is : %d\n",n);
	}
}

void main()
{
	int choice;
	struct queue* rear = NULL; 
	struct queue* front = NULL;

	do
	{
	printf("Please enter your choice: \n");
	printf("1 : Insert\n");
	printf("2 : Delete\n");
	printf("0 : EXIT\n");

	scanf("%d",&choice);
	switch(choice)
	{
	case 1 :Insert(&rear,&front);
		    break;
	case 2 :delete(&rear,&front);
		    break;
	case 0: printf(" Thank You \n");
		    break;
	default: printf("Invalid choice\n");
	}
}while(choice!=0);
getch();
}