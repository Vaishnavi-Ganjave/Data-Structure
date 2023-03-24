/*
que: write c program for implementation of queue using array.
Owner: vaishnavi ganjave
Batch: PPA9
*/


//solution:

#include<stdio.h>
#include<conio.h>
#define max 10

struct queue
{
	int arr[max];
	int front;
	int rear;
};


void init_queue(struct queue* qptr)
{
	qptr -> front = -1;
	qptr -> rear = -1;
}

int isfull(struct queue* qptr)
{
	return qptr -> rear == max-1;
}

int isempty(struct queue* qptr)
{
	return qptr -> rear == qptr -> front;
}

void insert(struct queue* qptr, int data)
{
	if(!isfull(qptr))
	{
		(qptr -> rear)++;
		qptr -> arr[qptr -> rear] = data;
	}
	else
	{
		printf("queue is full\n");
	}
}

int delete(struct queue* qptr)
{
	int n;
	if(!isempty(qptr))
	{
		(qptr -> front)++;
		n = qptr -> arr[qptr -> front];
		return n;
	}
	else
	{
		printf("queue is empty\n");
	}
}

void main()
{
	struct queue Q;
	int data;
	int choice;
	init_queue(&Q);

	do
	{
		printf("1. insert\n");
	    printf("2. delete\n");
		printf("0. exit\n");
		printf("enter your choice: \n");
		scanf("%d", &choice);

		switch(choice)
		{
		case 1: printf("enter a data: ");
			    scanf("%d", &data);
			    insert(&Q, data);
			    break;
		case 2: data = delete(&Q);
			    printf("delete data is: %d\n", data);
		     	break;
		case 0: printf("THANK YOU");
		    	break;
		default: printf("invalid choice\n");
		    	break;
		}
	}while(choice != 0);
	getch();
}

