

/*
void reverse(struct node* head)
{
	struct node* newnode = *head;            //p
	struct node* tempnode = *head;            //q
	struct node* data = *head;                  //r
	
	newnode = newnode->next->next;
	tempnode = tempnode->next;
	data->next = NULL;
	tempnode->next = data;

	while(newnode != NULL)
	{
		data = tempnode;
		tempnode = newnode;
		newnode = newnode->next;
		tempnode->next = data;
	}
	*head = tempnode;

}   */