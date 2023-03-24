
/* 
Que: write c program for quick sort
Owner name: Vaishnavi Ganjave
Batch: PPA9
*/

//solution:

#include<stdio.h>
#include<conio.h>


void quick_sort(int a[], int lb, int ub)
{
	int pivot, low,high,temp;
	pivot = a[lb];
	low = lb + 1;
	high = ub;
	while(low <= high)
	{
		while(a[low] < pivot)
		{
			low++;
		}
		while(a[high] > pivot)
		{
			high--;
		}
		if(low <= high)
		{
			temp = a[low];
			a[low] = a[high];
			a[high] = temp;
			low++;
			high--;
		}
	}
	temp = a[lb];
	a[lb] = a[high];
	a[high] = temp;
	if(lb < high)
	{
		quick_sort(a, lb, high-1);
	}
	if(low < ub)
	{
		quick_sort(a, low, ub);
	}
} 
 void main()
{
int a[100];
int i,n,j,temp;

printf("enter the size of element:\n");
scanf("%d",&n);
printf("enter the array element:\n");

for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("unsorted array is:\n");
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
} 
quick_sort(a,0,n-1);
printf("sorted array is:\n");
for(j=0;j<n;j++)
{
printf("%d\n",a[j]);
}
getch();
}