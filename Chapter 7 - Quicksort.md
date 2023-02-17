```py

Ch7.1
quicksort (p171)
pivot element - element around which a subarray
        is partitioned
Divide - Partition (rearrange) the array into 2
        subarrays, such that the lower half elements
        are all less than the pivot element,
        and the upper half are all greater than the
        pivot element
    - also computes the index of the pivot element
Conquer - sort the two subarrays by recursive calls
        to quicksort
Combine - because they're sorted in place, no other
        work is needed to combine them

Loop invariant:
(1) If p≤k≤i, then A[k] ≤ x
(2) If (i+1)≤k≤(j-1), then A[k] > x
(3) If k=r, then A[k] = x
Initilization - 
    first two conditions of the loop invariant
        are trivially satisfied (evaluate to false)
    int x = A[r]; assignment satisfies 3rd condition
Maintenance - 
    the swapping action only happens on elements
        right next to the pivot position, meaning
        that when i++ happens, the first element
        larger than x is swapped with the current
        (j) element that has been verified smaller
        than x, then j++ happens and the pivot
        position is moved to match
Termination - at termination, j=r, therefore
        all values are partitioned into 3 sets
        ≥x, ≤x, and x (which is then swapped
        with the pivot position)

Ch7.2
partition running time = Θ(n)
    - depends on partitioning "balance"
balance - if the two sides of a partion are the
        same sized, then its balanced
    - reflected in the recurrence that describes
        the running time
    - worst case running time occurs when the
        partitioning routine produces one subproblem
        with n-1 elements and one with 0 elements
    T(n) = T(n-1) + T(0) + Θ(n)
    - best case partioning occurs when the
        partition produces two equally sized
        subproblems
    T(n) = 2*T(n/2) + Θ(n)
    - constant proportionality - O(n*lg(n))
    - Partition splits are more balanced than 9to1
        80% of the time, and less balanced 20%
    - average case Partition produces a mix
    - even if you have a bad split, the average
        case produces a good split on the next one

Ch7.3
randomized quicksort (p179)
    add randomization to an algorithm to obtain
        good expected performance over all inputs
random sampling - randomly choose a pivot from
        the subarray A[p:r], in order to create
        an expected pair of subarrays that are
        reasonably well balanced on average
Randomized_Partition(A,p,r)
Randomized_Quicksort(A,p,r)

Ch7.4
Analysis of quicksort (p180)
T(n) = max (T(q) + T(n-q-1) + Θ(n))
    substituting: T(n) ≤ c*n²
T(n) ≤ max(c*q² + c(n-q-1)²) + Θ(n)
     = c*max(q² +  (n-q-1)²) + Θ(n)
    2nd derivative w/respect to q is positive?
expected running time = Θ(n*lg(n))
- running time is dominated by time spent in the
        Partition procedure
    - can be at most "n" calls to Partition
    - one call to Partition takes O(1) time,
        plus time proportional to number of
        for loop iterations
Lemma 7.1 (p182)
    X = number of comparisons performed in Partition
    Quicksort has O(n+X) running time
Partition separates the array into two sets,
    - pivot element is the only thing compared
        against to separate the sets
    - numbers from the first set are not directly
        compared to the second set
    - pivot element previously used, is never
        used again
    - two elements are compared if and only if
        the first element to be chosen as a pivot
        is one of the two numbers to be compared