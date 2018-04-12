#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quicksort(int data[], int left, int right)
{
    int pivot, i, j;
    if (left >= right) { return; }
    pivot = data[left];
    i = left+1;
    j = right;
    while (1){
        while (i <= right){
            if (data[i] > pivot){
                break;
            }
            i = i + 1;
        }
		while (j > left){
            if (data[j] < pivot){
                break;
            }
            j = j - 1;
        }
        if (i > j) { break; }
        swap(&data[i], &data[j]);
    }

    swap(&data[left], &data[j]);

    quicksort(data, left, j - 1);
    quicksort(data, j + 1, right);
}


int main()
{
    int i, n=100;
    int A[n];
	//int A[10]={7,2,6,8,3,1,9,5,4,0};
	for (i=0;i<n;i++){
		A[i]=rand()%100;
		printf("%2d, ",A[i]);
	}
	printf("\n");

    quicksort(A, 0, n-1);
    
    for (i = 0; i < n; i++)
    {
        printf("%2d, ",A[i]);
    }
    printf("\n");
    return 0;
}




