#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
	int i,j,k;
	int n=100;
	int A[n];
	//int A[10]={7,2,6,8,3,1,9,5,4,0};

	
	for (i=0;i<n;i++){
		A[i]=rand()%100;
		printf("%2d, ",A[i]);
	}
	printf("\n");
	
	for (i=0;i<n-1;i++){
		for (j=0;j<n-1;j++){
			if (A[j]>A[j+1]){
				swap(&A[j],&A[j+1]);			 
			}	
			/*for (k=0;k<n;k++){
				printf("%2d, ",A[k]);
			}
			printf("\n");*/
		}
	}
	
	for (i=0;i<n;i++){
		printf("%2d, ",A[i]);
	}
	printf("\n");
	
	return 0;
		
}
