#include <stdio.h>
#include <stdlib.h>


int main()
{
	printf("Kindly enter the number of elements: ");
    int n;
    int i=0;
    scanf("%d",&n);

    int arr[n];
    printf("Kindly enter the array elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

	mergeSort(arr,0, n-1);

	printf("\nSorted array is \n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
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
