
#include<stdio.h>
#include<conio.h>

void binary_search(int a[], int low, int high, int search)
{
	int mid;
//merge_sort(a,0,high);
if(search < a[low] || search > a[high])
{
printf("element is not found\n");
} 
else
{
	mid = (low + high)/2;
if(a[mid] == search)
	{
		printf("element is found\n");
	}

   else if(search < a[mid])
    {
	binary_search(a, low, mid-1, search);
	}
  else
    {
	binary_search(a, mid+1, high, search);
    }
}
} 

   void main()
   {
	   int a[10],search,i,n;
	   printf("enter how many elements u want:\n");
	   scanf("%d", &n);
	   printf("enter the elements:\n");

	   for(i=0;i<n;i++)
	   {
		   scanf("%d", &a[i]);
	   }
	   printf("enter element to search:\n");
	   scanf("%d",&search);

	   binary_search(a, 0, n, search);
		getch();
}