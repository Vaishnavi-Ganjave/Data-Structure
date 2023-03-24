#include<stdio.h>
#include<conio.h>

struct stud
{
	int a;
	int b;
	int c;
};

void main()
{
	struct stud d;
	d.a = 10;
	d.b = 20;
	d.c = 30;
	setvalues(&d);
	printf("%d\n%d\n%d",d.a,d.b,d.c);
}

void setvalues(struct stud *p)
{
	p->a = 110;
	p->b = 220;
	p->c = 330;

getch();
}