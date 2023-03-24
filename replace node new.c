
/* 
Q. write c program to replace node in linked list
Owner: Vaishnavi Ganjave
Batch: PPA9
*/


//new

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

int countnode(struct node* head)
{
 int count = 0;
 while(head != NULL)
 {
  count++;
  head = head->next;
 }
 return count;
}

void replacenode(struct node** head)
{
 int pos,i,n;
 struct node* newnode = NULL;
    struct node* tempnode =* head;   
 struct node* deletenode = NULL;  

 printf("enter a position: \n");
 scanf("%d", &pos);
 n = countnode(*head);
newnode = createnode();
    if(*head == NULL)
  {
     printf("linked list not available\n");
  }
 else if(pos == 1 && n == 1)
  {
   tempnode = newnode;
  }
 else if(pos < 1 || pos > n)
 {
    printf("invalid position\n");
    replacenode(head);
    }
 else if(pos == 1)
 {
  newnode->next = tempnode->next;
  free(tempnode);
  *head = newnode;
 }
else if(pos == n)
 {
  while(tempnode->next->next != NULL)
  {
   tempnode = tempnode->next;
  }
     free(tempnode->next);
     tempnode->next = newnode;
 }
 else
 {
  for(i = 1; i < pos-1; i++)
  {
           tempnode = tempnode->next;
  }
        deletenode = tempnode->next;
        newnode->next = deletenode->next;
        tempnode->next = newnode;
        free(deletenode);
   }

}

void main()
{
 int choice;
 struct node* first = NULL;

 do
 {
 printf("1. createlinkedlist()\n");
 printf("2. displaylinkedlist()\n");
 printf("3. replacenode()\n");
 printf("please enter your choice\n");
 scanf("%d", &choice);

  switch(choice)
  {
  case 1: createlinkedlist(&first);
   break;
  case 2: displaylinkedlist(first);
   break;
  case 3: replacenode(&first);
   break;
  case 0: printf("THANK YOU\n");
   break;
  default: printf("invalid choice\n");
  }
 }while(choice != NULL);
 getch();
}