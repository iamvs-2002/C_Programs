#include<stdio.h>
int factorial(int x);
int main()
{
	int a,fact;
	printf("Enter the number=");
	scanf("%d",&a);
	fact=factorial(a);
	printf("Factorial=%d",fact);
	return 0;
}
int factorial(int x)
{
	int f,i=1;
	for(f=x;f>=1;f--)
	{
		i=i*f;
	}
	return(i);
}
