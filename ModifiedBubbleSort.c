#include<stdio.h>

int main(){
    printf("Kindly enter the number of elements: ");
    int n;
    scanf("%d",&n);

    int arr[n];
    printf("Kindly enter the array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    ModifiedBubbleSort(n,arr);

    printf("\nThe sorted array elements are: \n");
    for(int a=0;a<n;a++){
        printf("%d ",arr[a]);
    }
}

void ModifiedBubbleSort(int n, int arr[]){
    for(int i=0; i<n; i++){
        int flag = 0;
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                flag =1;
            }
        }
        if(flag == 0){
            return;
        }
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x=*y;
    *y=temp;
}