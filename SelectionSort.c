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
    SelectionSort(n,arr);

    printf("\nThe sorted array elements are: \n");
    for(int a=0;a<n;a++){
        printf("%d ",arr[a]);
    }
}
void SelectionSort(int n, int arr[]){
    
    for(int j=0;j<n-1;j++){
        int min=j;
        int k=0;
        for(k = j;k<n;k++){
            if (arr[k]<arr[min])
            {
                min=k;
            }
        }
        swap(&arr[j],&arr[min]);
    }
}
void swap(int *x, int *y){
    int temp = *x;
    *x=*y;
    *y=temp;
}