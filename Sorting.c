#include<stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);
void randomizedquicksort(int arr[], int left, int right);
void quicksort(int arr[], int left, int right);
int partition(int arr[], int left, int right, int pivot);
void heapify(int arr[], int n, int i);
void heap_sort(int arr[], int n);
void countingSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int l, int m, int r);
void radix_sort (int a[], int n);
int maxvalue (int a[], int n);
void Bucket_Sort(int array[], int n);


struct bucket 
{
    int count;
    int* value;
};

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

    printf("\n\nUsing which method do you want to sort the array:\n");
    printf("1. Merge Sort\n");
    printf("2. Quick Sort\n");
    printf("3. Randomized Quick Sort\n");
    printf("4. Heap Sort\n");
    printf("5. Counting Sort\n");
    printf("6. Radix Sort\n");
    printf("7. Bucket Sort\n");

    int c;
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        printf("Applying Merge Sort Algorithm:\n");
        mergeSort(arr,0, n-1);
        break;
    case 2:
        printf("Applying Quick Sort Algorithm\n");
        quicksort(arr,0, n-1);
        break;
    case 3:
        printf("Applying Randomized Quick Sort Algorithm\n");
        randomizedquicksort(arr,0, n-1);
        break;
    case 4:
        printf("Applying Heap Sort Algorithm\n");
        heap_sort(arr,n);
        break;
    case 5:
        printf("Applying Counting Sort Algorithm\n");
        countingSort(arr,n);
        break;
    case 6:
        printf("Applying Radix Sort Algorithm\n");
        radix_sort(arr,n);
        break;
    case 7:
        printf("Applying Bucket Sort Algorithm\n");
        bucketSort(arr, n);
        break;
    
    default:
        return;
        break;
    }

	printf("\nSorted array is \n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;	
}
int compareIntegers(const void* first, const void* second)
{
    int x = *((int*)first), y =  *((int*)second);
    if (x == y)
    {
        return 0;
    }
    else if (x < y)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void bucketSort(int array[],int n)
{
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].value = (int*)malloc(sizeof(int) * n);
    }
    
    for (i = 0; i < n; i++)
    {
        if (array[i] < 0)
        {
            buckets[0].value[buckets[0].count++] = array[i];
        }
        else if (array[i] > 10)
        {
            buckets[2].value[buckets[2].count++] = array[i];
        }
        else
        {
            buckets[1].value[buckets[1].count++] = array[i];
        }
    }
    for (k = 0, i = 0; i < 3; i++)
    {
        // now using quicksort to sort the elements of buckets
        qsort(buckets[i].value, buckets[i].count, sizeof(int), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++)
        {
            array[k + j] = buckets[i].value[j];
        }
        k += buckets[i].count;
        free(buckets[i].value);
    }
}

int maxvalue (int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void radix_sort (int a[], int n)
{
    int bucket[10][10], bucket_cnt[10];
    int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
    lar = maxvalue (a, n);
    while (lar > 0){
        NOP++;
        lar /= 10;
    }
    for (pass = 0; pass < NOP; pass++){
        for (i = 0; i < 10; i++){
            bucket_cnt[i] = 0;
        }
        for (i = 0; i < n; i++){
            r = (a[i] / divisor) % 10;
            bucket[r][bucket_cnt[r]] = a[i];
            bucket_cnt[r] += 1;
        }
        i = 0;
        for (k = 0; k < 10; k++){
            for (j = 0; j < bucket_cnt[k]; j++){
                a[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;
    }
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int left, int right)
{
	if (left < right) {
	
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);//left-mid
		mergeSort(arr, mid + 1, right);//mid-right

		merge(arr, left, mid, right);
	}
}

void countingSort(int arr[], int n) 
{
    int arr1[10];
    int x = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > x)
        x = arr[i];
    }    
    int count_arr[10];
    for (int i = 0; i <= x; ++i) {
        count_arr[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count_arr[arr[i]]++;
    }
    for (int i = 1; i <= x; i++) {
        count_arr[i] += count_arr[i - 1];
    }   
    for (int i = n - 1; i >= 0; i--) {
        arr1[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = arr1[i];
    }
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

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

int partition(int arr[], int left, int right, int pivot) 
{
    int leftPointer = left -1;
    int rightPointer = right;

    while(leftPointer < rightPointer) 
    {
        while(arr[++leftPointer] < pivot) {
         //do nothing
        }
		
        while(rightPointer > 0 && arr[--rightPointer] > pivot) {
         //do nothing
        }

        if(leftPointer < rightPointer) {
            swap(leftPointer,rightPointer);
        }
    }
    swap(&leftPointer,&right);
    return leftPointer;
}

void quicksort(int arr[],int first,int last){
    int i, j, pivot, temp;

    if(first<last){
        pivot=first;
        i=first;
        j=last;

        while(i<j){
            while(arr[i]<=arr[pivot]&&i<last)
                i++;
            while(arr[j]>arr[pivot])
                j--;
            if(i<j){
                swap(&arr[i],&arr[j]);
            }
        }
        swap(&arr[pivot],&arr[j]);
        quicksort(arr,first,j-1);
        quicksort(arr,j+1,last);
    }
}

void randomizedquicksort(int arr[],int first,int last){
    int i, j, pivot, temp;

    int point=first+rand()%(last-first+1);

    if(first<last){
        pivot = arr[point];
        i=first;
        j=last;

        while(i<j){
            while(arr[i]<=arr[pivot]&&i<last)
                i++;
            while(arr[j]>arr[pivot])
                j--;
            if(i<j){
                swap(&arr[i],&arr[j]);
            }
        }
        swap(&arr[pivot],&arr[j]);
        quicksort(arr,first,j-1);
        quicksort(arr,j+1,last);
    }
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}