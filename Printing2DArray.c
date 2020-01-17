#include<stdio.h>
void display(int q[3][4],int row,int column);
int main()
{
	int a[3][4]={
					1,2,3,4,
					5,6,7,8,
					9,0,1,6
				};
	display(a,3,4);
	return 0;
}
void display(int q[3][4],int row,int column)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			printf("%d",q[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
