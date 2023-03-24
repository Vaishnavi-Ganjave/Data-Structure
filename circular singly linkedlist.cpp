                             
                                     // CIRCULAR SINGLY LINKEDLIST

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
	struct node* newnode=NULL;
	int value;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory not allocated\n");
	}
	else
	{
		printf("Enter the value\n");
		scanf("%d",&value);
		newnode->data=value;
		newnode->next=NULL;
	}
	return newnode;
}

void createlinkedlist(struct node** tail)
{
	struct node* newnode=NULL;
	struct node* tempnode=*tail;
	newnode=createnode();
	if(*tail==NULL)
	{
		*tail=newnode;
		newnode->next=newnode;
	}
	else
	{
		newnode->next=(*tail)->next;
		(*tail)->next=newnode;
		*tail=newnode;
	}
}

void display(struct node* tail)
{
	struct node* tempnode=NULL;
	if(tail==NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		tempnode=tail->next;
		printf("Data in Linked list is\n");
		do
		{
			printf("%d\t",tempnode->data);
			tempnode=tempnode->next;
		}while(tempnode!=tail->next);
	}
}

void insertatfirst(struct node** tail)
{
	struct node* newnode=NULL;
	newnode=createnode();
	if(*tail==NULL)
	{
		*tail=newnode;
		(*tail)->next=newnode;
	}
	else
	{
		newnode->next=(*tail)->next;
		(*tail)->next=newnode;
	}
}
		
void insertatlast(struct node** tail)
{
	createlinkedlist(tail);
}

 void insertatposition(struct node** tail)
{
	struct node* newnode=NULL;
	struct node* tempnode=NULL;
	int data,flag=0;
	if(*tail==NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		printf("Enter the data : ");
		scanf("%d",&data);

		if((*tail)->next->data==data)
		{
			insertatfirst(tail);
		}
		else if((*tail)->data==data)
		{
			insertatlast(tail);
		}
		else 
		{
			tempnode=(*tail)->next;
			do
			{
				if(tempnode->next->data==data)
				{
					newnode=createnode();
					newnode->next=tempnode->next;
					tempnode->next=newnode;
					flag=1;
					break;
				}
			tempnode=tempnode->next;
			}while(tempnode!=(*tail)->next);
			if(flag==0)
		{
			printf("data is not present\n");
			insertatposition(tail);
		}
		}
	}
}

void main()
{
	int choice;
	struct node* last = NULL; 
	do
	{
	
	printf("1 : CreateLinkedList \n");
	printf("2 : DisplayLinkedList \n");
	printf("3 : Insertatfirst  \n");
	printf("4 : Insertatlast \n");
	printf("5 : Insertatposition \n");
	printf("0 : exit \n");
	printf("Please enter your choice \n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:createlinkedlist(&last);
	    	break;
	case 2:display(last);
		    break;
	case 3:insertatfirst(&last);
	    	break;
	case 4:insertatlast(&last);
	    	break;
	case 5:insertatposition(&last);
	    	break;
	case 0: printf(" Thank You \n");
		    break;
	default: printf("Invalid choice \n");
	}
}while(choice!=0);
getch();
}























/*
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct node
{
	int data;
	struct node* next;
};

struct node * createnode()
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
		printf("please enetr a value\n");
		scanf("%d", &value);

		newnode -> data = value;
		newnode -> next = NULL;
	}
		return newnode;
}

void createlinkedlist(struct node** tail)
{
	  struct node* newnode = NULL;
	  struct node* tempnode = *tail;
	  newnode = createnode();
	  if(*tail == NULL)
	{
		*tail = newnode;
		newnode -> next = newnode;        //*tail->next = newnode;
	}
	  else
	{
		newnode->next = (*tail) -> next;
	   ( *tail)-> next = newnode;
	   *tail = newnode;
	}
}

void displaylinkedlist(struct node* tail)
{
	struct node* tempnode = NULL;
	if(tail == NULL)
	{
		printf("linked list is empty\n");
	}
	else
	{
		tempnode = tail ->next;
		printf("data in linked list\n");
		do
	{
		printf("%d=>", tempnode->data);
		tempnode = tempnode -> next;
	}
		while(tempnode != tail->next);
	}
}

void insertatfirst(struct node** tail)
{
	  struct node* newnode = NULL;
	  newnode = createnode();
	  if(*tail == NULL)
	{
		*tail = newnode;
		(*tail) -> next = newnode;
	}
	  else
	{
		newnode->next = (*tail) -> next;
	   ( *tail)-> next = newnode;
    }
}

void insertatlast(struct node** tail)
{
	createlinkedlist(tail);
}

void insertatposition(struct node** tail)
{
	struct node* newnode = NULL;
	struct node* tempnode = NULL;

	int pos;
	int flag;
	printf("please enter a position \n");
	scanf("%d", &pos);
	
	if((*tail)->next->data == pos)
	{
		insertatfirst(tail);
	}
	else if((*tail)->data == pos)
	{
		insertatlast(tail);
	}
	else
	{
		tempnode = (*tail)->next;
		do
		{
			if(tempnode->next->data == pos)
    	{
		    newnode = createnode();
			newnode -> next = tempnode -> next;
		    tempnode -> next = newnode;
			flag = 1;
			break;
		}
		    tempnode = tempnode->next;
	}
		while(tempnode != (*tail)->next);
		if(flag == 0)
		{
			printf("data not present\n");
			insertatposition(tail);
		}
	}
}



void main()
{
	   int choice;
	   struct node* tail = NULL;

	   do
	   {
	    printf("1. createlinkedlist()\n");
		printf("2. displaylinkedlist()\n");
		printf("3. insertatfirst()\n");
		printf("4. insertatlast()\n");
		printf("5. insertatposition()\n");
		printf("0: exit\n");
	    printf("please enter your choice\n");
	    scanf("%d", &choice);

		 switch(choice)
		  {
		    case 1: createlinkedlist(&tail);
			        break;
		    case 2: displaylinkedlist(tail);
			        break;
			case 3: insertatfirst(&tail);
				    break;
			case 4: createlinkedlist(&tail);
			        break;
			case 5: insertatposition(&tail);
				    break;
		    case 0: printf("THANK YOU\n");
			        break;
		    default: printf("invalid choice\n");
		 }
	}
	   while(choice != NULL);
	   getch();
}

*/