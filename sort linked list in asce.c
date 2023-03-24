
/*
Q3. Write c program to sort an given linked list in ascending order
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

  
/*

void insertatfirst(struct node** head)
{
	  struct node* newnode = NULL;
	  newnode = createnode();
	  if(*head == NULL)
	{
		*head = newnode;
	}
	  else
	{
		newnode->next = *head;
	    *head = newnode;
    }
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

void insertatposition(struct node** head)
{
	struct node* newnode = NULL;
	struct node* tempnode = *head;

	int pos;
	int n,i;
	printf("please enter a position \n");
	scanf("%d", &pos);
	n = countnode(*head);
	if(pos == 1)
	{
		insertatfirst(head);
	}
	else if(pos == n+1)
	{
		createlinkedlist(head);
	}
	else if(pos < 1 || pos > n+1)
	{
		printf("invalid position");

		insertatposition(head);
	}   
	else
	{
		    newnode = createnode();
		for(i = 1; i < pos-1; i++)
		{
			tempnode = tempnode->next;
			
		}
		    newnode->next = tempnode->next;
			tempnode->next = newnode;
	}
}

*/

void sort(struct node* head)
{
	int i,n;
	int sort;
	struct node *temp = NULL;
	struct node* tempnode = head;
	if(head == NULL)
	{
		printf("linked list not available\n");
	}
	else
	{
		while(tempnode->next != NULL)
	{
			temp = tempnode->next;
			while(temp != NULL)    
		{
			if(tempnode->data > temp->data)
			{
	          	sort = tempnode->data;
	            tempnode->data = temp->data;
	            temp->data = sort;
			}
			 temp  = temp->next;
	}
		tempnode = tempnode->next;
		//printf("ascending order is %d\n", head->data);
   }
 }
}

void main()
{
	int choice;
	struct node* first = NULL;

	printf("1. createlinkedlist()\n");
	printf("2. displaylinkedlist()\n");
	printf("3. insertatfirst()\n");
    printf("4. insertatlast()\n");
    printf("5. insertatposition()\n");
	printf("6. sort a linked list\n");
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
		/*	case 3: insertatfirst(&first);
			break;
			case 4: createlinkedlist(&first);     
			break;
			case 5: insertatposition(&first);
			break;  */
		    case 6: sort(first);
			break;
	    	case 0: printf("THANK YOU\n");
			break;
		    default: printf("invalid choice\n");
		}
	}
	while(choice != NULL);
	getch();
}












