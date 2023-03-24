
/*
Que: write c program to sort array using merge sort
Owner: Vaishnavi Ganjave
Batch: PPA9
*/

//solution:

#include<stdio.h>
#include<conio.h>

void merge(int a[],int low,int mid,int high)
{
	int b[10];
	int i,j,k;
	i=low;
	j=mid+1;
	k=0;

	while(i <= mid && j <= high)
	{
		if(a[i] < a[j])
		{
			b[k] = a[i];
			i++;
			k++;
		}
		else
		{
			b[k] = a[j];
			j++;
			k++;
		}
	}

	while(i <= mid)
	{
		b[k] = a[i];
		i++;
		k++;
	}
	while(j <= high)
	{
		b[k] = a[j];
		j++;
		k++;
	}
	k=0;

	for(i=low; i<=high; i++)
	{
		a[i] = b[k];
		k++;
	}
}

void merge_sort(int a[],int low,int high)
{
	int mid;
	if(low < high) 
	{
		mid = (low + high)/2;

		merge_sort(a, low, mid);    
		merge_sort(a, mid+1, high); 
		merge(a,low, mid, high);   
	}
}

void main()
{
	int a[10];
	int n,i;
	
	printf("How many elements you want: \n");
	scanf("%d",&n);
	printf("Enter the array elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Unsorted array elements are: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");

	merge_sort(a,0,n-1);

	printf("Sorted array elements are: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	getch();
}

