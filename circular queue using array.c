
/* 
Que: program to implement circular queue using array
Owner: Vaishnavi Ganjave
Batch: PPA9
*/


//solution:

#include<stdio.h>
#include<conio.h>
#define max 10

struct circularqueue
{
	int arr[max];
	int front;
	int rear;
};

void init_circularqueue(struct circularqueue* qptr)
{
	qptr -> front = -1;
	qptr -> rear = -1;
}

int isfull(struct circularqueue* qptr)
{
	return ((qptr -> rear) +1) % max == qptr -> front ;
}

int isempty(struct circularqueue* qptr)
{
	return qptr -> rear == -1;

}

void insert(struct circularqueue* qptr)
{
	int data;

	if(isfull(qptr))
	{
		printf("queue is full \n");
	}
	else
	{
		printf("enter a data: \n");
		scanf("%d", &data);
		if(isempty(qptr))
		{
			qptr -> rear = 0;
			qptr -> front = 0;
		}
		else
		{
		qptr -> rear = ((qptr -> rear) +1) % max;
	
	}
	    qptr -> arr[qptr -> rear] = data;
}
}

int delete(struct circularqueue* qptr)
{
	int n;
	if(isempty(qptr))
	{
		printf("queue is empty\n");
		
	}
	else
	{
	     n = qptr -> arr[qptr -> front];
		 if(qptr -> front == qptr -> rear)
		 {
			 qptr -> front = -1;
			 qptr -> rear = -1;
		 }
		 else
		 {
	     	qptr -> front = (qptr -> front+1) % max;
		 }
	     	printf("delete element: %d\n", n);
		return n;
	}
}

void main()
{
	struct circularqueue Q;
	int choice;
	init_circularqueue(&Q);

	do
	{
		printf("1. insert\n");
	    printf("2. delete\n");
		printf("0. exit\n");
		printf("enter your choice: \n");
		scanf("%d", &choice);

		switch(choice)
		{
		case 1: insert(&Q);
			    break;
		case 2: delete(&Q);5
		     	break;
		case 0: printf("THANK YOU");
		    	break;
		default: printf("invalid choice\n");
		    	break;
		}
	}while(choice != 0);
	getch();
}
