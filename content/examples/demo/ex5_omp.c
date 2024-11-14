#include <stdio.h>
#include <math.h>
#define NX 102400

int main(void){
    double vecA[NX],vecB[NX],vecC[NX];

    /* Initialize vectors */
    for (int i = 0; i < NX; i++) {
    vecA[i] = 1.0;
    vecB[i] = 1.0;
    }
    #pragma omp target teams distribute parallel for simd map(to:vecA[0:NX],vecB[0:NX]) map(from:vecC[0:NX])
    {
    for (int i = 0; i < NX; i++) {
       vecC[i] = vecA[i] + vecB[i];
    }
    }

    double sum = 0.0;
    for (int i = 0; i < NX; i++) {
       sum += vecC[i];
    }
    printf("The sum is: %8.6f \n", sum);
}
