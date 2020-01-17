#include<stdio.h>
void display(int x,int *y);
int main ()
{
	int arr[5]={0,1,2,3,4};
	for(int i=0;i<5;i++)
		display(arr[i],&arr[i]);
	return 0;	
}
void display(int x,int *y)
{
	printf("Element=%d and Address=%d and, Element=%d and Address=%d\n",x,y,*y,y);
}
