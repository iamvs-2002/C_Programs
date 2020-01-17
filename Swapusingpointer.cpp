#include<stdio.h>
int swap(int *x,int *y);
int main()
{
	int a,b;
	printf("Enter the 2 no=");
	scanf("%d%d",&a,&b);
	swap(&a,&b);
	printf("%d %d",a,b);
	return 0;
}
int swap(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}
