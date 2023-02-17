#include <stdio.h>
#include <limits.h>

#define n 5

void main()
{
    int array[n] = {5,3,6,9,2};

    for (int i = 0; i < n-1; i++)
    {
        int y = i;
    //find the smallest element in the array
        for (int j = i+1; j < n; j++)
        {
            if (array[j] < array[y])
            {
                y = j;
            }
        }
    //swap that element with the current i position
        int z = array[i];
        array[i] = array[y];
        array[y] = z;
    }
    for (int q = 0; q < n; q++)
    {
        printf("ordered array: %d, %d\n", q, array[q]);
    }
}