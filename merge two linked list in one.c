
/*
Q6. Write c program to merge two different linked list in third linked list
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

void displaylinkedlist(struct node* head)
{
	while(head != NULL)
	{
		printf("%d=>", head->data);
		head = head->next;
	}
	printf("\n");
}


void mergeLL(struct node** head1, struct node**head2 , struct node** head3)
{
	int i,n,n1,n2;
	struct node* tempnode1 = *head1;
	struct node* tempnode2 = *head2;
	struct node* tempnode3 = NULL;
	struct node* newnode = NULL;
	n1 = countnode(*head1);
	n2 = countnode(*head2);
	n = n1+n2;

	if(*head1 != NULL && *head2 != NULL)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		*head3 = newnode;
		tempnode3 = *head3;
		tempnode3->data = tempnode1->data;
		tempnode3->next = NULL;

		for(i =1; i<n1; i++)
		{
			newnode = (struct node*)malloc(sizeof(struct node));
			tempnode3->next = newnode;
			tempnode3 = newnode;
			tempnode1 = tempnode1->next;
			tempnode3->data = tempnode1->data;
			tempnode3->next = NULL;
		}
		for(i =n1; i<n; i++)
		{
			newnode = (struct node*)malloc(sizeof(struct node));
			tempnode3->next = newnode;
			tempnode3 = newnode;
			tempnode3->data = tempnode2->data;
			tempnode2 = tempnode2->next;
			tempnode3->next = NULL;
		}
		displaylinkedlist(*head3);
	}
	else
	{
		printf("merge operation not works\n");
	}
}

void main()
{
	int choice;
	struct node* first = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	do
	{
	printf("1. create linkedlist()\n");
	printf("2. create second linkedlist()\n");
	printf("3. display first linkedlist()\n");
	printf("4. display second linkedlist()\n");
	printf("5.merge both linkedlist()\n");
	printf("please enter your choice\n");
	scanf("%d", &choice);

		switch(choice)
		{
		case 1: createlinkedlist(&first);
			break;
		case 2: createlinkedlist(&second);
			break;
		case 3: displaylinkedlist(first);
			break;
		case 4: displaylinkedlist(second);
			break;
		case 5: mergeLL(&first, &second,&third);
			break;
		case 0: printf("THANK YOU\n");
			break;
		default: printf("invalid choice\n");
		}
	}
	while(choice != NULL);
	getch();
}
