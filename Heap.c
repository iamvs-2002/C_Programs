#include <stdio.h>
int size = 0;

int main()
{
    printf("Kindly enter the number of elements: ");
    int n;
    int i=0;
    scanf("%d",&n);

    int arr[n];
    printf("Kindly enter the array elements: ");
    for(i=0;i<n;i++){
        int ss;
        scanf("%d",&ss);
        insert(arr,ss);
    }

    printf("Max-Heap array: ");
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    printf("\nKindly enter the element you want to delete: ");
    int x;
    scanf("%d",&x);
    deleteRoot(arr, x);

    printf("After deleting an element: ");
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert(int array[], int newNum)
{
    if (size == 0)
    {
        array[0] = newNum;
        size += 1;
    }
    else
    {
        array[size] = newNum;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
        heapify(array, size, i);
        }
    }
}
void deleteRoot(int array[], int num)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == array[i])
        break;
    }

    swap(&array[i], &array[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }
}

void heapify(int array[], int size, int i)
{
    if (size == 1)
    {
        printf("Single element in the heap");
    }
    else
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l] > array[largest])
        largest = l;
        if (r < size && array[r] > array[largest])
        largest = r;
        if (largest != i)
        {
        swap(&array[i], &array[largest]);
        heapify(array, size, largest);
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
