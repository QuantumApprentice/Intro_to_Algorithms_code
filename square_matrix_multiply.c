#include <stdio.h>
#include <stdlib.h>

int* square_matrix_mult(int* A, int* B, int rows)
{
    int n = rows;
    int* Array_C = (int*)malloc(n*n*sizeof(int));
    int c;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c = 0;
            for (int k = 0; k < n; k++)
            {
                c += A[n*i+k] * B[n*k+j];
            }
            Array_C[n*i+j] = c;
        }
    }
    return Array_C;
}

void main()
{
    int Array_A[16] = 
        { 2, 4, 6, 8,
         10,12,14,16,
         18,20,22,24,
         26,28,30,32 };
    int Identity[16] = 
        { 1, 0, 0, 0,
          0, 1, 0, 0,
          0, 0, 1, 0,
          0, 0, 0, 1 };
    int Array_B[16] = 
        { 2, 0, 0, 1,
          0, 2, 1, 0,
          0, 1, 2, 0,
          1, 0, 0, 2 };
    int* Array_C = square_matrix_mult(Array_A, Array_B, 4);

    printf("a\tb\tc\td\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t%d\t%d\t%d\n", Array_C[i*4], Array_C[i*4+1], Array_C[i*4+2], Array_C[i*4+3]);
    }
}