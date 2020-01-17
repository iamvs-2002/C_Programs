#include<stdio.h>
main()
{
	int n,arr[n],i,j,t;
	printf("Enter the no of intrgers=");
	scanf("%d",&n);
	printf("Enter the no=");
	for(j=0;j<n;j++)
		scanf("%d",arr[j]);
	for(j=0;j<n-1;j++)
	{
		for(i=0;i<n-j-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				t=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=t;
			}	
		}			
	}	
	for(j=0;j<n;j++)
		printf("%d \n",arr[j]);
}