#include <stdio.h>

int main() {
    printf("Kindly enter the number of elements: ");
    int n;
    int i=0;
    scanf("%d",&n);

    int arr[n];
    printf("Kindly enter the array elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

	quickSort(arr,0, n-1);

	printf("\nSorted array is \n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}



int partition(int left, int right, int pivot) {
    int leftPointer = left -1;
    int rightPointer = right;

    while(true) {
        while(intArray[++leftPointer] < pivot) {
         //do nothing
        }
		
        while(rightPointer > 0 && intArray[--rightPointer] > pivot) {
         //do nothing
        }

        if(leftPointer >= rightPointer) {
            break;
        } else {
            printf(" item swapped :%d,%d\n", intArray[leftPointer],intArray[rightPointer]);
            swap(leftPointer,rightPointer);
        }
    }
	
    printf(" pivot swapped :%d,%d\n", intArray[leftPointer],intArray[right]);
    swap(leftPointer,right);
    printf("Updated Array: "); 
    display();
    return leftPointer;
}

void quickSort(int left, int right) {
    if(right-left <= 0) {
        return;   
    } else {
        int pivot = intArray[right];
        int partitionPoint = partition(left, right, pivot);
        quickSort(left,partitionPoint-1);
        quickSort(partitionPoint+1,right);
    }        
}


void swap(int num1, int num2) {
    int temp = intArray[num1];
    intArray[num1] = intArray[num2];
    intArray[num2] = temp;
}

