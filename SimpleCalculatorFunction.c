#include<stdio.h>
float sum(int x,int y);
float diff(int x,int y);
float product(int x,int y);
float remainder(int x,int y);
float modulo(int x, int y);
int main()
{
	int a,b;
	char c;
	printf("Enter any 2 no=");
	scanf("%d%d",&a,&b);
	printf("Enter the operator=");
	scanf("%c",&c);
	switch(c)
		case +: printf("Addition");
				sum(a,b);
				break;
		case -: printf("Subtraction");
				diff(a,b);
				break;
		case *: printf("Product");
				product(a,b);
				break;
		case /: printf("Remainder a/b");
				remainder(a,b);
				break;		
		case %: printf("Quotient a/b");
				modulo(a,b);
				break;	
		default: printf("Invalid");	
	return(0);								
}
float sum(int x,int y)
{
	float d;
	d=x+y;
	printf("Sum=%f",d);
}
float diff(int x,int y)
{
	float d;
	d=x-y;
	printf("Diff=%f",d);
}
float product(int x,int y)
{
	float d;
	d=x*y;
	printf("Product=%f",d);
}
float remainder(int x,int y)
{
	float d;
	d=x/y;
	printf("Remainder=%f",d);
}
float modulo(int x,int y)
{
	float d;
	d=x%y;
	printf("Quotient=%f",d);
}
