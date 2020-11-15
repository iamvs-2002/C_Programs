#include<stdio.h>
void function();
int func(int x);
int main()
{
	function();
	int a;
	printf("Enter the no=");
	scanf("%d",&a);
	func(a);
	printf("Im in main.\n");
	function();
	return 0;
}
void function()
{
	printf("Im in funtion.\n");
}
int func(int x)
{
	printf("Im in func and a=%d",x);
	return x;
}
