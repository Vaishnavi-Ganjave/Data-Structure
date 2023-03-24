
#include<stdio.h>
#include<conio.h>
void main()
{
	int a[5],f=0,i,n,no;
	printf("enter elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter no to search:");
	scanf("%d",&no);
	for(i=0;i<5;i++)
	{
		if(a[i]==no)
		{
			f=1;
			break;
		}
		if(f==1)
			printf("number found");
		else
            printf("number not found");
	}
		getch();
	}


