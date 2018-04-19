#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*
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
*/ 
void quickmed(int data[],int med, int left, int right)
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
	if (j == med) { return; }
	else if (j < med ){
		quickmed(data, med, j + 1, right);
	}
	else{
		quickmed(data, med, left, j - 1);		
	}
	
    //quickmed(data, med, left, j - 1);
    //quickmed(data, med, j + 1, right);
}

int main()
{
    int i, n=1000;
    int m=n/2-1;
    int A[n];
	//int A[10]={4,2,6,8,3,1,9,5,7,0};
	for (i=0;i<n;i++){
		A[i]=rand()%100;
		printf("%2d, ",A[i]);
	}
	printf("\n");

    quickmed(A, m, 0, n-1);
    printf("median =%2d,\n",A[m]);
    for (i = 0; i < n; i++){
        printf("%2d, ",A[i]);
    }
    printf("\n");
    return 0;
}




