// IMPLEMENTATION OF LIST USING LINK LIST
#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int data;
	struct node*next;
}node;
node *head=NULL, *newn, *temp, *t;

void insert();
void del();
void display();

void main()
{
	int ch;
	printf("\n\n$$$ SINGLY LINKED LIST $$$\n\n");
	while(1)
	{
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
		printf("Enter your choice: \t");
		scanf("%d", &ch);

		switch (ch)
		{
			case 1: insert(); break;
			case 2: del(); break;
			case 3: display(); break;
			case 4: exit(0);
			default: printf("Enter the correct option \n");
			 break;
		}
	}
}
void insert()
{
	int no, op;
	newn =(node*)malloc(sizeof(node));
	printf("Enter the element to be inserted: \t");
	scanf("%d", &newn->data);
	printf("1. Insert at first\n2. Insert at middle\n3. Insert at last\n");
	printf("\nEnter your choice: ");
	scanf("%d", &op);
	switch(op)
	{
		case 1: if (head==NULL)
			{
				head=newn;
				head->next=NULL;
			}
			else
			{
				newn->next=head;
				head=newn;
			}
			break;
		case 2: if (head->next==NULL)
			{
				printf("Single node entry so insertion in not allowed\n");
			}
			else
			{
				printf("Enter the data ofter which the element to be inserted: \t");
				scanf("%d",&no);
				temp=head;
				while (temp -> data!=no)
				{
					temp=temp->next;
				}
				newn->next=temp->next;
				temp->next=newn;
			}
			break;
		case 3: temp = head;
			if (head==NULL)
			{
				head=newn;
				newn->next=NULL;
			}
			else
			{
				while (temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=newn;
				newn->next=NULL;
			}
			break;
	}
}
void del()
{
	int op, no;
	if (head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("1. Deletion at first\n2. Deletion at middle\n3. Deletion at last\n");
		printf("Enter your choice: \t");
		scanf("%d", &op);
		switch(op)
		{
			case 1: if(head->next==NULL)
				{
					printf("The deleted element is: %d", head->data);
					head=NULL;
				}
				else
				{
					temp=head;
					head=head->next;
					printf("The deleted element is: %d", temp->data);
					free (temp);
				}
				break;
			case 2: if (head->next==NULL)
				{
					printf("Single node entry cannot perform deletion\n");
				}
				else
				{
					printf("Enter the element to be deleted: \t");
					scanf("%d", &no);
					temp=head;
					while (temp->data!=no)
					{
						t=temp;
						temp=temp->next;
					}
					printf("The deleted element is: %d", temp->data);
					t->next=temp->next;
					}
					break;
		       case 3: temp=head;
			       if (head->next==NULL)
			       {
				printf("The deleted element is: %d", head->data);
				head=NULL;
			       }
			       else
			       {
				while (temp->next!=NULL)
				{
				 t=temp;
				 temp=temp->next;
				}
				 t->next=NULL;
				 printf("The deleted element is: %d", temp->data);
				}
		}
	}
}
void display()
{
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		temp=head;
		printf("The elements is a list are: \n");

		while (temp!=NULL)
		{
			printf("%d\n", temp->data);
			temp=temp->next;
		}
	}
}