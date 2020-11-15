#include<stdio.h>
int fact(int x);
int main()
{
	int a,f;
	printf("Enter the number=");
	scanf("%d",&a);
	f=fact(a);
	printf("Factorial=%d",f);
	return 0;
}
int fact(int x)
{
	int f;
	if(x==1)
	{
		return 1;
	}
	else
	{
		f=x*fact(x-1);
		return f;
	}
}
