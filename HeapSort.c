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

	heap_sort(arr,n);

	printf("\nSorted array is \n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

void heap_sort(int arr[], int n)
{
    int i;
    for (i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]); //Move the largest element at root to the end
        heapify(arr, i, 0); //Apply heapify to reduced heap
    }
}

void heapify(int arr[], int n, int i)
{
    int left, right, largest;
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    // Check if left child exists and is larger than its parent
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // Check if right child exists and larger than its parent
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if root is not the largest
    if (largest != i) {
        swap(&arr[i], &arr[largest]); //make root the largest
        heapify(arr, n, largest); // Apply heapify to the largest node
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


