#include<stdio.h>
main()
{
	int d1,d2,m1,m2,y1,y2,y,mm1=0,mm2=0,daysviayears,daysviadays,daysviamonths,i,j,k,count=0,a,b,Days ;
	int daysinmonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	printf("Enter the first date=");
	scanf("%d,%d,%d",&d1,&m1,&y1);
	printf("Enter the second date=");
	scanf("%d,%d,%d",&d2,&m2,&y2);
	if((d1>0 && d1<=31) && (m1>0 && m1<=12) && (y1>0) && (d2>0 && d2<=31) && (m2>0 && m2<=12) && (y2>0))
	{
		y=y2-y1-1;
		daysviayears=y*365;
		for(i=m1+1; i<=12; i++)
		{
			mm1=daysinmonth[i]+mm1;
		}
		for(j=m2-1; j>=0;j--)
		{
			mm2=daysinmonth[j]+mm2;
		}	
		daysviadays=daysinmonth[m1]-d1+d2;
		daysviamonths=mm1+mm2;
		for(k=y1+1; k<=y2-1; k++)
		{
			if(k/400==0 || (k/4==0 && k/100!=0))
				count=count+1;
			else{count=0;}
		}	
		if((y1/400==0 || (y1/4==0 && y1/100!=0)) && (m1==1 || (m1==2 && d1<=29)))
			a=1;
		else{a=0;}
		if((y2/400==0 || (y2/4==0 && y2/100!=0)) && (m2>2 || (m2==2 && d2==29)))
			b=1;
		else{b=0;}
		Days=daysviayears+daysviamonths+daysviadays+count+a+b;
		printf("The no. of days=%d",Days);
	}
	else{printf("The dates entered are invalid.");}	
} 
