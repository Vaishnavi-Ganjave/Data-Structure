

/* 
Que: write c program for Bubble sort
Owner name: Vaishnavi Ganjave
Batch: PPA9
*/

//solution:

#include<stdio.h>
#include<conio.h>


void bubble_sort(int a[], int n)
{
	int i, j,temp;
    for(i = 1; i < n; i++)
	{
		for(j = 0; j < n - i; j++)
		{
			if(a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void main()
{
	int i,n;
	int a[10];
	printf("please enter total number of elements: ");
	scanf("%d", &n);
	printf("please enter array elements: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	printf("unsorted array elements:");
	for(i = 0; i < n; i++)
	{
	printf("%d\t", a[i]);
	}
	printf("\n");

	bubble_sort(a,n);

	printf("sorted array elements:");
	for(i = 0; i < n; i++)
	{
	printf("%d\t", a[i]);
	}
	getch();
}
