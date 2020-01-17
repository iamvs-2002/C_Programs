#include<stdio.h>
#define MAX 500
int main(){
	char ch;
	char arr[MAX];
	printf("Enter the character=");
	scanf("%c",&ch);
	printf("Enter the sentence=");
	scanf("%[^\n]s",arr);
	printf("The character u entered=%c",ch);
	printf("The sentence u entered=%s",arr);
	char str[20];
	printf("Enter the string=");
	scanf("%[^\n]%*c",str);
	printf("The string u entered=%s",str);
	return 0;

}