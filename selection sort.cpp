

   /* 
   Que: write c program for Selection sort
   Owner: Vaishnavi ganjave
   Batch: PPA9
   */


//solution:

#include<stdio.h>
#include<conio.h>

void selection_sort(int a[], int n)
{
	int i, j, temp;
for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void main()
{
	int i,n;
	int a[10],temp;
	printf("please enter total number of elements: ");
	scanf("%d", &n);
	printf("please enter array elements: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	printf("unsorted elements are: ");
	for(i = 0; i < n; i++)
	{
	printf("%d\t", a[i]);
	}
	printf("\n");

	selection_sort(a,n);

	printf("sorted elements are: ");
	for(i = 0; i < n; i++)
	{
	printf("%d\t", a[i]);
	}

	getch();
}
