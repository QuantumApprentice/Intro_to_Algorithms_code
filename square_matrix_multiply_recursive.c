#include <stdio.h>
#include <stdlib.h>

int* square_matrix_mult_recursive(int*A, int*B, int rows);
struct tmp_matrix* assign(struct tmp_matrix* matrix, int* Array_A, int size);
int* partition(int*old_array, int x, int y, int size);
int* add_matrices(int* A, int* B, int size);
void merge_matrices(int* merged_matrix, int*A, int x, int y, int new_size);

struct tmp_matrix {
    int* p11;
    int* p21;
    int* p12;
    int* p22;
};

int* square_matrix_mult_recursive(int*A, int*B, int rows)
{
    int n = rows;
    int* Array_C = (int*)malloc(n*n*sizeof(int));
    struct tmp_matrix tmpA;
    struct tmp_matrix tmpB;

    struct tmp_matrix tmpC;

    tmpC.p11 = (int*)malloc(n*n*sizeof(int)/4);
    tmpC.p21 = (int*)malloc(n*n*sizeof(int)/4);
    tmpC.p12 = (int*)malloc(n*n*sizeof(int)/4);
    tmpC.p22 = (int*)malloc(n*n*sizeof(int)/4);

    if (n==1) {
        Array_C[0] = A[0] * B[0];
    }
    else {
        assign(&tmpA, A, rows);
        assign(&tmpB, B, rows);

        tmpC.p11 = add_matrices(square_matrix_mult_recursive(tmpA.p11, tmpB.p11, rows/2),
                                square_matrix_mult_recursive(tmpA.p12, tmpB.p21, rows/2),
                                rows);
        tmpC.p12 = add_matrices(square_matrix_mult_recursive(tmpA.p11, tmpB.p12, rows/2),
                                square_matrix_mult_recursive(tmpA.p12, tmpB.p22, rows/2),
                                rows);
        tmpC.p21 = add_matrices(square_matrix_mult_recursive(tmpA.p21, tmpB.p11, rows/2),
                                square_matrix_mult_recursive(tmpA.p22, tmpB.p21, rows/2),
                                rows);
        tmpC.p22 = add_matrices(square_matrix_mult_recursive(tmpA.p21, tmpB.p12, rows/2),
                                square_matrix_mult_recursive(tmpA.p22, tmpB.p22, rows/2),
                                rows);

        merge_matrices(Array_C, tmpC.p11, 0,0, rows);
        merge_matrices(Array_C, tmpC.p21, 0,1, rows);
        merge_matrices(Array_C, tmpC.p12, 1,0, rows);
        merge_matrices(Array_C, tmpC.p22, 1,1, rows);
    }
    return Array_C;
}

struct tmp_matrix* assign(struct tmp_matrix* matrix, int* Array_A, int size)
{
    int n = size;
    matrix->p11 = (int*)malloc(n*n*sizeof(int)/4);
    matrix->p21 = (int*)malloc(n*n*sizeof(int)/4);
    matrix->p12 = (int*)malloc(n*n*sizeof(int)/4);
    matrix->p22 = (int*)malloc(n*n*sizeof(int)/4);

    matrix->p11 = partition(Array_A, 0, 0, size);
    matrix->p21 = partition(Array_A, 0, 1, size);
    matrix->p12 = partition(Array_A, 1, 0, size);
    matrix->p22 = partition(Array_A, 1, 1, size);
}

int* partition(int*old_array, int x, int y, int size)
{
    int n = size/2;
    int* new_array = (int*)malloc(n*n*sizeof(int));

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            new_array[n*r+c] = old_array[size*(r+n*y) + c+n*x];
        }
    }
    return new_array;
}

int* add_matrices(int* A, int* B, int size)
{
    int* new_array = (int*)malloc(size*size*sizeof(int));

    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            new_array[size*r+c] = A[size*r+c] + B[size*r+c];
        }
    }
    return new_array;
}

void merge_matrices(int* merged_matrix, int*A, int x, int y, int new_size)
{
    int n = new_size/2;

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            merged_matrix[new_size*(r+n*y) + c+n*x] = A[n*r+c];
        }
    }
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

    int* Array_C = square_matrix_mult_recursive(Array_A, Array_B, 4);

    printf("a\tb\tc\td\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t%d\t%d\t%d\n", Array_C[i*4], Array_C[i*4+1], Array_C[i*4+2], Array_C[i*4+3]);
    }
}








/*
[ 0, 1, 2, 3 ]
[ 4, 5, 6, 7 ]
[ 8, 9,10,11 ]
[12,13,14,15 ]

Icy_Black_Deep:
n*(r+y)+(c+x) for suitable x and y

VIPCodedByATool:
[size*(r+n*y) + (c+n*x)] for 0..1 x and y
*/