```py

Ch2.1
more vocabulary:
----------------------------------------
keys - the elements being sorted

insertion sort (p17) - remove one "key" at a time and 
        insert it into the correct position
    - to find the correct position, compare each
        "key" to the keys already inserted,
        from right to left
    - sorts the numbers in place (re-arranges
        numbers in the array)
    - with at most a constant number stored outside
        the array

Insertion_Sort(A) pseudocode:
for j = 2 to A.length
    key = A[j]
    //Insert A[j] into the sorted sequence A[1..j-1]
    i = j-1
    while i>0 and A[i]>key
        A[i+1] = A[i]
        i = i-1
    A[i+1] = key

loop invariant - used to show why an algorithm is
        correct
    - in Insertion_Sort()'s' case, "loop invariant"
        means the output array is sorted
    - at the start of each iteration of Insertion_Sort()'s'
        for loop, the subarray A[1..j-1] consists of
        the elements originally in A[1..j-1], but in
        sorted order
    - applies to while loops too?

initialization - it's' true prior to the first iteration
        of the loop
    - in Insertion_Sort()'s' case, the first element
        is skipped, and assumed to already be sorted
maintenance - if it is true before an iteration of the
        loop, it remains true before the next iteration
    - in Insertion_Sort()'s' case, the body of the loop
        needs to make sure the output is sorted
termination - when the loop terminates, the invariant
        has a "useful property" that shows the algorithm
        is correct 
    - Insertion_Sort()'s' case, the entire array is 
        sorted (p20)

mathematical induction (p19) - to prove a property holds
        by proving a base case and an inductive step
    - showing the invariant holds before the first
        iteration corresponds to the "base case"
    - showing the invariant holds from iteration
        to iteration corresponds to the inductive step
    - induction stops when loop terminates (as opposed
        to showing the iterations can continue to infinity)

pseudocode conventions:
    indentation - indicates block structure
    while, for, repeat-until, if-else loops -
    - similar to C/C++/Java/python/pascal
    - loop counter retains its value after exiting loop
    - for loops have an implicit increment built in
    to - used when a for loop increments
    downto - used when a for loop decrements
    by - used when counter change is greater than 1
    // - comment
    multiple assignment - i = j = e
    - all assigned from right to left
    scope - variables are local to the procedure
          - no global variables unless explicitly stated
    arrays[i] - normal C notation
    - indexing starts at [1] instead of [0]
    .. - indicates range of values
    . - dot notation - objects are composed of attributes
    - normal C++ usage
    - for array A[], A.length indicates length of array
    arrays and objects are treated as pointers
    - attribute notation can "cascade" - pointers to
        specific sub-elements of an object can be used
        to address their sub-elements
    NIL = NULL
    - paramaters are passed by value to procedures
    - arrays and objects are passed by reference
    return - immediately transfers "control" back to
        the calling procedure
        - can return multiple values
    boolean and/or are short-circuiting (if the first
        evaluates to false, the second isnt checked)
    error - indicates an error occurred

Ch2.2
"analyzing" an algorithm - predicting the resources
        that algorithm requires
RAM model - Random Access Machine technology model
        with generic single core processor
        with regular RAM (Random Access Memory)
    - instructions executed sequentially (not parallel)
    - data types are int and float
    size limit - int represented by c*log_2(n) bits
        for some constant c >= 1
    - no bit shifting except for small positive int

input size - varies by application
        typically either be total number of items
        or total number of bits (depends on situation)
running time - number of primitive operations/"steps"
    - a constant time is required for each line (p25)
    - execution of i'th' line takes time c_i (constant)
    - comments not executed (take no time)
T(n) - running time of the algorithm - sum of running
        times for each statement executed
    - sum the products of the "cost" and "times"
    - see example (p26)
linear function - best case running time for insertion
        sort (elements already sorted)
quadratic function - worst case running time for 
        insertion sort (elements in reverse order)
worst case running time - longest running time for any
        input of size n
    - gives an upper bound
    - can happen often
    - "average" case is usually about as bad as worst
probabalistic analysis - use randomized algorithm
        to yield "expected" running time

order/rate of growth -
    - only leading term is considered
        (lower order terms are relatively insignificant)
    - ignore leading terms constant coefficient
        (insignificant compared to leading coefficient)

Ch2.3
Divide and Conquer
Divide - break the problem into smaller subproblems
        similar to the original
Conquer - solve smaller problems recursively
Combine - combine the solutions
sentinel - unique value used to simplify code
        (like NULL terminator in char strings?)
recurrence equation - equation that determines the
        running time on an algorithm with a recursive
        call to itself
    - describes the running time on a problem of
        size n in terms of the running time on
        smaller inputs

T(n) = total time
for n <= c for some constant c, solution takes
        constant time Θ(1)
division yields (a) subproblems
    - each subproblem is (1/b) the size of the original
        (for some constant b, which is normally == a)
    - takes time T(n/b) to solve one subproblem (n/b)
    - and a*T(n/b) to solve (a) subproblems
D(n) - time it takes to divide the problem into
        subproblems
C(n) 0 time it takes to combine the subproblems

So T(n) is either Θ(1)
        or a*T(n/b) + D(n) + C(n)






--------------------------------------
(2.1-2)
Insertion_Sort(A) in reverse order pseudocode:
for j=2 to A.length
    key = A[j]
    i = j-1
    while i>0 and A[i]<key
        A[i+1] = A[i]
        i = i-1
    A[i+1] = key
--------------------------------------

(2.1-3)
linear_search(A):
input v = value
for j=1 to A.length
    if A[j] == v
        return j
return NIL
loop invariant = no index number less than j such that
                A[j] == v

--------------------------------------
(if binary addition overflows above 1)
Add_Binary(A[n], B[n])
{
C[n+1] = 0
for i=n+1 to 1
    if C[i] == 0
        C[i] = A[i-1] + B[i-1]
        if A[i-1] == 1 and B[i-1] == 1
            C[i-1] = 1

    else if C[i] == 1
        C[i] = C[i] + A[i-1] + B[i-1]
        if A[i-1] == 1 or B[i-1] == 1
            C[i-1] = 1
}
--------------------------------------
(if doing regular int addition but converting to binary)
Add_Binary(A[n], B[n])
{
    carry = 0
    C[n+1] = 0
    for i=n to 1
        C[i+1] = (A[i] + B[i] + carry) mod 2
        if (A[i] + B[i] + carry >= 2)
            carry = 1
        else carry = 0
    C[1] = carry
}
