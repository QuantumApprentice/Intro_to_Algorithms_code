#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

void merge_sort(int*A, int p, int r);
void merge(int*A, int p, int q, int r);

void main()
{
    int start = 0;
    int size  = 4;
    int A[5] = {5,4,6,2,1};

    merge_sort(A, start, size);

    for (size_t i = 0; i < size+1; i++)
    {
        printf("sorted array: %d, %d\n", i, A[i]);
    }
}

void merge_sort(int*A, int p, int r)
{
    if (p<r)
    {
        int q = floor((p+r)/2);
        merge_sort(A, p, q);
        merge_sort(A, (q+1), r);
        merge(A, p, q, r);
    }
}

void merge(int*A, int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;

    int *L = (int*)malloc(n1+1);
    int *R = (int*)malloc(n2+1);

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p+i-1];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[q+j];
    }

    L[n1+1] = INT_MAX;
    R[n2+1] = INT_MAX;

    int i=1, j=1;
    for (int k = 0; k < (r-p); k++)
    {
        if (L[i]<=R[j])
        {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}