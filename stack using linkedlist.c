/* 
Que : write C program stack implementation using Linked List.

Owner : Vaishnavi Ganjave

Batch : PPA9

*/



//solution



#include<stdio.h>

#include<conio.h>

#include<stdlib.h>

struct STACK 

{

	int data;

	struct STACK* next;



};




struct STACK* createnode()

{

	struct STACK* newnode=NULL;

	int value;

	newnode=(struct STACK*)malloc(sizeof(struct STACK));

	if(newnode==NULL)

	{

		printf("stack is full\n");

	}

	else

	{

		printf("Enter the value\n");

		scanf("%d" ,&value);

		newnode->data=value;

		newnode->next=NULL;

	}

	return newnode;

}




void push(struct STACK** top)

{

	struct STACK* newnode=NULL;

	newnode=createnode();



	if(*top==NULL)

	{

		*top=newnode;

	}

	else

	{

		newnode->next=*top;

		*top=newnode;

	}

}





int isempty(struct STACK* top)

{

	if(top==NULL)

	{

		return 1;

	}

	else

	{

		return 0;

	}

}




int pop(struct STACK** top)

{

	struct STACK* temp=NULL;

	int n;



	n=(*top)->data;

	temp=*top;

	*top=(*top)->next;

	free(temp);

	return n;

}



void main()

{

	struct STACK* top=NULL;

	int choice,data;

	

	do

	{

		printf("1 : push\n");

		printf("2 : pop\n");

		printf("0 : EXIT\n");

		printf("Enter your choice\n");

		scanf("%d",&choice);



		switch(choice)

		{

		case 1: push(&top);

			break;

		case 2: if(isempty(top))

				{

					printf("Stack is empty\n");

				}

				else

				{

					data=pop(&top);

					printf("%d\n",data);

				}

			break;

		case 0: printf("\n!! Thank you !!\n");

			   exit(0); 

				break;

		Default: printf("Invalid choice\n");

		}

	}while(choice!=0);

getch();

}