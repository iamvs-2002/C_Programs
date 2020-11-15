#include<stdio.h>
int main()
{
	int arr[5]={0,1,2,3,4};
	int i,*j;
	for(i=0;i<5;i++)
	{
		j= &arr[i];
		printf("Adrress =%d and element=%d\n",j,*j);
	}
}
