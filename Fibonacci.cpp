#include<stdio.h>
int fibbo(int x);
int main(){
	int n;
	printf("enter number:");
	scanf("%d",&n);
	fibbo(n);
	return 0;
}
int fibbo(int x){
	int a=0,b=1,c;
	for(int i=0;i<x;i++){
		if(i==0)
			printf("0\n");
		else if(i==1)
			printf("1");
		else{
			c=a+b;
			a=b;
			b=c;
			printf("\n%d",c);
		}
	}
	return 0;
}
