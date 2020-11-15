#include<stdio.h>
int main()
{
	int i=3,*q,**k;
	/*
	Here, i is an ordinary int 
		  q is a pointer to an int
		  k is pointer to an interger ponter
	*/
	char c='a',*w,**p;
	float j=0.2560,*e,**o;
	q=&i;
	w=&c;
	e=&j;
	k=&q;
	p=&w;
	o=&e;
	/*
		Address = %d, &i
		Value = %d, i == %d, *q == %d, **k == %d, *(&i)
	*/
	printf("Address of i=%u\n",&i);
	printf("Address of c=%u\n",&c);
	printf("Address of j=%u\n",&j);
	printf("Address of i=%d\n",q);
	printf("Address of c=%d\n",w);
	printf("Address of j=%d\n",e);
	printf("Value of i=%d\n",*q);//Value at the storage q
	printf("Value of c=%c\n",*w);
	printf("Value of j=%f\n",*e);
	printf("Value of i=%d\n",**k);
	printf("Value of c=%c\n",**p);
	printf("Value of j=%f\n",**o);
	
}
