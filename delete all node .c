 
/* 
Q7. write c program to clear given linked list(delete all node)
Owner: Vaishnavi Ganjave
Batch: PPA9
*/



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
		while(tempnode-> next != NULL)
		{
			tempnode = tempnode-> next;
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
void deleteatfirst(struct node** head)
{
	int temp1, temp2;
	struct node* tempnode = *head;
if(*head == NULL)
{
	printf("linked list not available");
}
    
else
{
     tempnode = *head;
     *head = (*head)->next;
     free(tempnode);
  }
}

void deleteatlast(struct node** head)
{
	struct node* tempnode = *head;
    if(*head == NULL)
{
	printf("linked list not available\n");
}
	else if((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
else
{
	while(tempnode->next->next != NULL)
	{
		tempnode = tempnode->next;
	}
	free(tempnode->next);
	tempnode->next = NULL;
	}
}

void deleteatposition(struct node** head)
{
	struct node* tempnode = *head;
	struct node* deletenode = NULL;
	int pos;
	int i,n;
	printf("please enter a position \n");
	scanf("%d", &pos);
	n = countnode(*head);
	if(pos == 1)
	{
		deleteatfirst(head);
	}
	else if(pos == n)
	{
		deleteatlast(head);
	}
	else if(pos < 1 || pos > n )
	{
		printf("invalid position\n");
		deleteatposition(head);
	}
	else
	{
		for(i = 1; i< pos-1; i++)
		{
			tempnode = tempnode->next;
		}
		deletenode = tempnode->next;
		tempnode->next = deletenode->next;
		free(deletenode);
    }
}

void deleteallnode(struct node** head)
{
	struct node* tempnode = *head;
	while(*head != NULL)
	{
		tempnode = *head;
		*head = (*head)->next;
		free(tempnode);
	}
	printf("delete succesufully\n");
}
void main()
{
	   int choice;
	   struct node*first = NULL;

	    printf("1. createlinkedlist()\n");
		printf("2. displaylinkedlist()\n");
		printf("3. deleteatfirst()\n");
		printf("4. deleteatlast()\n");
		printf("5. deleteatposition()\n");
		printf("6. deleteallnode()\n");
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
			
			case 3: deleteatfirst(&first);
				    break;
			case 4: deleteatlast(&first);
				    break;
			 case 5: deleteatposition(&first);
					break;  
			 case 6: deleteallnode(&first);
				 break;
		    case 0: printf("THANK YOU\n");
			        break;
		    default: printf("invalid choice\n");
		 }
	}
	   while(choice != NULL);
	   getch();
}