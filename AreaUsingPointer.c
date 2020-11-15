#include<stdio.h>
float area_circle(int *x);
float area_square(int *y);
int main()
{
	int r,s,area;
	float ar;
	char a;
	printf("Enter the figure=");
	scanf("%c",&a);
	if(a=='c')
	{
		printf("Enter the radius=");
		scanf("%d",&r);
		ar=area_circle(&r);
		printf("Area of circle=%f",ar);
	}
	else if(a=='s')
	{
		printf("Enter the side=");
		scanf("%d",&s);
		ar=area_square(&s);
		printf("Area of square=%f",ar);
	}
	return 0;
}
float area_circle(int *x)
{
	float area;
	area=3.14*(*x)*(*x);
	return(area);
}
float area_square(int *y)
{
	float area;
	area=(*y)*(*y);
	return(area);
}
