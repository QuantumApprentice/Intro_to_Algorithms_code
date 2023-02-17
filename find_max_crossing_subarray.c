#include <stdio.h>
#include <limits.h>
#include <math.h>

struct sub_values {
    int low;
    int high;
    int sum;
};

void find_max_crossing_subarray(int* Array, int low, int mid, int high, struct sub_values* max_val)
{
    int left_sum = INT_MIN;
    int sum = 0,
        max_left = 0,
        max_right = 0;

    for (int i = mid; i >= low; i--)
    {
        sum += Array[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0, max_right = 0;

    for (int j = (mid+1); j <= high; j++)
    {
        sum += Array[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    max_val->low   = max_left;
    max_val->high  = max_right;
    max_val->sum   = left_sum + right_sum;
}

void find_max_subarray(int* Array, int low, int high,
                  struct sub_values* max_val)
{
    struct sub_values left;
    struct sub_values right;
    struct sub_values cross;

    if (high == low)
    {//return this stuff
        max_val->low  = low;
        max_val->high = high;
        max_val->sum  = Array[low];
    }
    else {
        int mid = floor((low+high)/2);
        find_max_subarray(Array, low, mid, &left);
        find_max_subarray(Array, mid+1, high, &right);
        find_max_crossing_subarray(Array, low, mid, high, &cross);

        if (left.sum >= right.sum && left.sum >= cross.sum)
            {
                max_val->low  = left.low;
                max_val->high = left.high;
                max_val->sum  = left.sum;
            }
        else if (right.sum >= left.sum && right.sum >= cross.sum)
        {
                max_val->low  = right.low;
                max_val->high = right.high;
                max_val->sum  = right.sum;
        }
        else {
                max_val->low  = cross.low;
                max_val->high = cross.high;
                max_val->sum  = cross.sum;
        }
    }
}

void main()
{
    int Array[16] = {13,-3,-25,20, -3,-16,-23,18,
                     20,-7, 12,-5,-22, 15, -4, 7};

    struct sub_values max_val;
    find_max_subarray(Array,
                      0, 15,
                      &max_val);

    printf("low:     %d\nhigh:    %d\nmax_sum: %d\n",
            max_val.low+1,
            max_val.high+1,
            max_val.sum);
}