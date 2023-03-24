

/* 
Q5. write c program to find out maximum element from first half of the linked list and minimum from second half of the linked list
Owner: Vaishnavi Ganjave
Batch : PPA9
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


void max_min(struct node* head)
{
	int max= head->data;
	int i,n;
	int min = max;
	struct node* tempnode = head;
	n = countnode(head);
	for(i = 0; i<n/2; i++)
	{
		if(max < head->data)
		{
			max = head->data;
		}
			head = head->next;
		
	}
	printf("maximum element is %d\n", max);

	for( i = n/2; i<n; i++)
	{
		if(min > head->data)
		{
			min = head->data;
		}
			head = head->next;
	}
	
		printf("minimum element is %d\n", min);
	}

	

void main()
{
	int choice;
	struct node* first = NULL;

	printf("1. createlinkedlist()\n");
	printf("2. displaylinkedlist()\n");
	printf("3. max_min element()\n");
	
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
		case 3: max_min(first);
			break;
		case 0: printf("THANK YOU\n");
			break;
		default: printf("invalid choice\n");
		}
	}
	while(choice != NULL);
	getch();
}
