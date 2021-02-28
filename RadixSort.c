    #include<stdio.h>

    int main (){
        printf("Kindly enter the number of elements: ");
        int n;
        int i=0;
        scanf("%d",&n);

        int arr[n];
        printf("Kindly enter the array elements: ");
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        radix_sort(arr,n);

        printf("\nSorted array is \n");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return 0;
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
    