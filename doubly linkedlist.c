

                       // DOUBLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct node
{
	struct node* prev;
	int data;
	struct node* next;
};

//function for createnode
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

		newnode -> prev = NULL;
		newnode -> data = value;
		newnode -> next = NULL;
		
	}
		return newnode;
}

//function for create linkedlist
void createlinkedlist(struct node** head, struct node** tail)
{
	  struct node* newnode = NULL;
	  newnode = createnode();
	  if(*head == NULL) 
	{
		*head = newnode;  
		*tail = newnode;
	}
	  else
	{
	    (*tail)->next = newnode; 
        newnode->prev = *tail; 
        *tail = newnode; 
	}
}

//function for reverse linkedlist
void reverse(struct node* tail)
{
 while(tail != NULL)
	{
		printf("%d=>", tail->data);
		tail = tail->prev;
	}
	   printf("\n");
}


//function for display linkedlist
void displaylinkedlist(struct node* head)
{
	while(head != NULL)
	{
		printf("%d=>", head->data);
		head = head->next;
	}
	   printf("\n");
}

//function for insertatfirst
void insertatfirst(struct node** head, struct node** tail)
{
	  struct node* newnode = NULL;
	  newnode = createnode();
	  if(*head == NULL)
	{
		*head = newnode;
	//	*tail = newnode;
	}
	  else
	{
		newnode->next = *head;
		(*head)->prev = newnode;
	    *head = newnode;
    }
}

//function for countnode
int countnode(struct node * head, struct node* tail)
{
	int count = 0;
	while(head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

//function for insertatposition
void insertatposition(struct node** head, struct node** tail)
{
	struct node* newnode = NULL;
	struct node* tempnode = *head;

	int pos;
	int n,i;
	printf("please enter a position \n");
	scanf("%d", &pos);
	n = countnode(*head, *tail);
	if(pos == 1)
	{
		insertatfirst(head, tail);
	}
	else if(pos == n+1)
	{
		createlinkedlist(head, tail);
	}
	else if(pos < 1 || pos > n+1)
	{
		printf("invalid position");

		insertatposition(head, tail);
	}   
	else
	{
		    newnode = createnode();
		for(i = 1; i < pos-1; i++)
		{
			tempnode = tempnode->next;
			
		}
		    newnode->prev = tempnode;
		    newnode->next = tempnode->next;
			tempnode->next = newnode;
			newnode->next->prev = newnode;
	}
}

//function for deleteatfirst
void deleteatfirst(struct node** head, struct node** tail)
{
    if(*head == NULL)
{
	printf("linked list not available");
}
	else if((*head)->next == NULL)
	{
		free(*head);
		*head = *tail = NULL;
	}
   else
{
	   *head = (*head)->next;
	   free((*head)->prev);
	   (*head)->prev = NULL;    
  }
}

//function for deleteatlast
void deleteatlast(struct node** head, struct node** tail)
{
	struct node* tempnode = *head;
    if(*head == NULL)
{
	printf("linked list not available\n");
}
	else if((*head)->next == NULL)
	{
		free(*head);
		*head = *tail = NULL;
	}
else
{
	tempnode = (*tail)->prev;
	tempnode->next = NULL;
	free(*tail);
	*tail = tempnode;
	}
}

//function for deleteatposition
void deleteatposition(struct node** head,struct node** tail )
{
	struct node* tempnode = *head;
	int pos;
	int i,n;
	printf("please enter a position \n");
	scanf("%d", &pos);
	n = countnode(*head, *tail);
	if(pos == 1)
	{
		deleteatfirst(head, tail);
	}
	else if(pos == n)
	{
		deleteatlast(head, tail);
	}
	else if(pos < 1 || pos > n )
	{
		printf("invalid position\n");
		deleteatposition(head, tail);
	}
	else
	{
		for(i = 1; i< pos; i++)
		{
			tempnode = tempnode->next;
		}
		tempnode->prev->next = tempnode->next;
		tempnode->next->prev = tempnode->prev;
		free(tempnode);
    }
}




void main()
{
	   int choice;
	   struct node*first = NULL;
	   struct node* tail = NULL;

	   do
	   {
	    printf("1. createlinkedlist()\n");
		printf("2. displaylinkedlist()\n");
		printf("3. reverse()\n");
		printf("4. insertatfirst()\n");
		printf("5. insertatlast()\n");
		printf("6. insertatposition()\n");
		printf("7. deleteatfirst()\n");
		printf("8. deleteatlast()\n");
		printf("9. deleteatposition()\n");
		printf("0. exit\n");
        printf("please enter your choice\n");
	    scanf("%d", &choice);

		 switch(choice)
		  {
		    case 1: createlinkedlist(&first, &tail);
			        break;
		    case 2: displaylinkedlist(first);
			        break;
			case 3: reverse(tail);
			        break;
			case 4: insertatfirst(&first, &tail);
			        break;
			case 5: createlinkedlist(&first, &tail);
			        break;
			case 6: insertatposition(&first, &tail);
			        break;
			case 7: deleteatfirst(&first, &tail);
				    break;
			case 8: deleteatlast(&first, &tail);
				    break;
			case 9: deleteatposition(&first, &tail);
				    break;
		    case 0: printf("THANK YOU\n");
			        break;
		    default: printf("invalid choice\n");
		 }
	}
	   while(choice != NULL);
	   getch();
}