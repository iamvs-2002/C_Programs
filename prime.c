#include <stdio.h>

int main(){
	int num,i,a;
	printf("Enter the number till which you want the prime numbers:");
	scanf("%d", &num);
	for(i=2;i<=num;i++)
	{
	    int k=0;
	    for(int j=2;j<i;j++)
	    {
	        if(i%j ==0)
	        {
	            k=1;
	            break;
	        }
	    }
	    if(k==0)
	    {
	        printf("%d ",i);
	    }
	}
	return 0;
}
