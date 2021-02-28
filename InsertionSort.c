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
    InsertionSort(n,arr);

    printf("\nThe sorted array elements are: \n");
    for(int a=0;a<n;a++){
        printf("%d ",arr[a]);
    }
}

void InsertionSort(int n, int arr[]){
    for(int i=1;i<n;i++){
        int j = i-1;
        int key = arr[i];
        while(arr[j]>key && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


void swap(int *x, int *y){
    int temp = *x;
    *x=*y;
    *y=temp;
}