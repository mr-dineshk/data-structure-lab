//ARRAY IMPPLEMENTATION OF LINK ADT
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int list [5], i, n = 0;

void create();
void insert(int x, int p);
void delete(int p);
void display();

void main()
{
	int x, p, c;

	clrscr();
	printf("$$$ LIST ADT USING ARRAY $$$\n\n");

	while(1)
	{
		printf("\nThe operations are: ");
		printf("\n1.CREATE\t2.INSERT\t3.DELETE\t4.DISPLAY\t5.EXIT\n");
		printf("Enter your choice: ");
		scanf("%d",&c);

		switch(c)
		{
			case 1: create();
				break;
			case 2: printf("Enter the element and position: ");
				scanf("%d%d", &x, &p);
				insert (x, p);
				break;
			case 3: printf("Enter the position of element to be deleted: ");
				scanf("%d",&p);
				break;
			case 4: display();
				break;
			case 5: exit(0);

			default: printf("Enter valid choice: ");
				 break;
		}
	}
}
void create()
{
	int e, i;
	printf("\nEnter the number of elements: ");
	scanf("%d", &e);

	printf("\nEnter the elements: ");
	for (i = 0; i < e; i++)
	{
		scanf("%d", &list[i]);
	}
	n = e;
}
void insert(int x, int p)
{
	if (n == 5)
		printf("List is full...");
	else if ((p<0)||(p>n))
		printf("Postition is invalid");
	else
	{
		for (i = n - 1; i >= p; i--)
		{
			list[i+1] = list[i];
		}
		list[p] = x;
		n++;
	}
}
void delete (int p)
{
	if (n==0)
		printf("List is empty");
	else if ((p<0)||(p>n-1))
		printf("Position is invalid");
	else
	{
		for (i=p; i<n; i++)
		{
			list[1] = list[i+1];
		}
		n--;
	}
}
void display()
{
	int p;
	if (n==0)
		printf("List is empty");
	else
	{
		printf("The elements present in the list are: \n");
		printf("\nElement\tposition\n\n");
		for(p=0; p<n; p++)
		{
			printf("%d\t%d\n\n", list[p], p);
		}
	}
}
