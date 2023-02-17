```py

Ch8.1
comparison sorts - algorithms that sort based only
        on comparisons between input elements
    - merge sort & heapsort are asymptotically
        optimal, no sort exists that is faster by
        more than a constant factor
    - tests x<y, x≤y, x==y, x≥y, x>y
    - this section assumes all elements are unique
        so x==y is useless
    - all other comparisons yield identical
        information about the relative order
    - assume all comparisons are x≤y

decision tree - full binary tree that represents
        the comparisons between elements,
        performed by a sorting algorithm,
        operating on an input of a given size
    - all other aspects of algorithm are ignored
- any correct sorting algorithm must be able to
        produce each permutation of its input
    - annotate each internal node by i:j,
        i,j in range 1≤i, j≤n (n=number of elements)
    - annotate each leaf by permutation
        (π = function,
         π(i) i = index location of the element)
        <π(1), π(2), ..., π(n)>
    - each of the n! permutations on n elements
        must appear as one of the leaves of the
        decision tree
    - each of these leaves must be "reachable"
        from the root
worst case - length of the longest simple path
        from the root of a decision ree to any
        of its reachable leaves
    - equals the height of its decision tree

Theorem 8.1 (p193)
Any comparison sort algorithm requires Ω(n*lg(n))
        comparisons in the worst case

Corollary 8.2
Heapsort and Merge sort are asymptotically optimal
        comparison sorts

Ch8.2
counting sort - assumes each of n input elements
        is an integer in the range 0 to k
    - when k=O(n), the sort runs in Θ(n) time
    - determines, for each x, the number of
        elements less than x
    - uses this to place x directly into the
        correct position in output array
    - uses 3 arrays, input, output, temp storage
    - only works for integer arrays
    - sorts by creating an empty array,
        then populating that array with a count
        of the number of times each number
        in A appears in A

Counting_Sort(A,B,k) (p195)

"stable" algorithm - numbers with the same value
        appear in the output array in the same
        order as they do in the input array
    - this "stability" lends counting sort to
        "radix sort"

Ch8.3
radix sort - sorts into different bins by the
        least significant digit first
    - combines the bins in order
    - sorts into different bins again by the
        2nd least significant digit
    - combine and repeat
    - runs through the set of numbers based on
        the number of digits in each element
    - needs to be a "stable" sort method
    - uses more memory than other sort methods
Radix_Sort(A,d) (p198) code

Ch8.4
bucket sort - assumes input is drawn from a
        a uniform random distribution
        over the interval [0,1)
    - average-case running time O(n)
    - divides the interval [0,1) into n equal
        sized subintervals(buckets),
        then distributes them into more buckets(
Bucket_Sort(A) (p201)
    - assumes input is an n-element array,
    - each element A[i] satisfies 0≤A[i]<1
    - requires an auxiliar array B[0:n-1] of
        linked lists
    - assumes mechanism for maintaining the list
(rest of the chapter is analysis)
    - as long as input has the property that
        that the sum of squares of the bucket
        size is linear in the total number of
        elements, eq 8.1 tells us bucket sort
        will run in linear time

here the cheatsheet, you just remember it 
1. it is cheap to copy and you dont modify the thing inside the container, use copy. (auto)
2. you want to modify the thing inside the container to use lvalue-reference. (auto&)
3. it not cheap to copy and you dont want to modify the thing inside the container, use const lvalue-reference. (const auto&)
4. you want to move the element from the container to somewhere else then use rvalue-referenece. (auto&&)


