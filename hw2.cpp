#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <omp.h>

int main(){
	int N=700;
	int A[N][N],x[N],b[N],c[N];
	int i,j;
	clock_t t0,t1,T0,T1;
	
	srand(time(NULL));       //building the matrix A and x
	for(i=0;i<N;i++){
		x[i]=rand()%1000;
		//printf("%2d= %2d, \n",i,x[i]) ;
		for (j=0;j<N;j++){
			A[i][j]=rand()%1000;			
		}		
	}
	//regularlly matrix product
	t0 = clock();
	for (i=0; i<N; i++) {
        b[i] = 0;
        for (j=0; j<N; j++)
            b[i] = b[i] + A[i][j]*x[j];
    }
    t1 = clock();
    for (i=0; i<N; i++){
    	printf("%6d\n", b[i]);
	} 
	
	
	//parallel matrix product
	T0 = clock();
	#pragma omp parallel for reduction(+: j)
	for (i=0; i<N; i++) {
        c[i] = 0;
        for (j=0; j<N; j++)
            c[i] = c[i] + A[i][j]*x[j];
    }
    T1 = clock();
    for (i=0; i<N; i++){
    	printf("%6d\n", c[i]);
	} 
	
	printf("\ntime for matrixproduct= %.4f s\n", (t1-t0)/(double)(CLOCKS_PER_SEC));
	printf("\ntime for parallel matrixproduct= %.4f s\n", (T1-T0)/(double)(CLOCKS_PER_SEC));
        
	
	
	return 0;
}
