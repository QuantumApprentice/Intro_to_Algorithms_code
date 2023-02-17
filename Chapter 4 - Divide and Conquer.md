```py

Ch4.1
recursive case - when subproblems, from the divide
        and conquer method, are large enough to
        solve recursively
base case - when subproblems are small enough that
        the algorithm no longer recurses
        (or it "bottoms out")
recurrence - equation or inequality that describes
        a function in terms of its value
        on smaller inputs

3 methods for solving recurrences:
1) substitution method - guess a bound then use
        mathematical induction to prove correct
2) recursion-tree method - converts the recurrence
        into a tree whose nodes represent the costs
        incurred at various levels of the recursion
        (solve recurrences w/techniques for
        bounding summations)
3) master method - provides bounds for recurrences
        of the form --
        T(n) = a*T(n/b) + f(n)
        where a>=1, b>1, f(n) is a function
        (requires memorization of 3 cases)

recurrences that are inequalities
    - example: T(n) ≤ 2T(n/2) + Θ(n)
    - uses O()/Ω() notation instead of Θ() notation

technicalities that are ignored:
    - floor/ceiling values created in the divide step
        are ignored
    - boundary conditions (edge cases?) are also
        ignored,
        assume T(n) is constant for small n

Maximum Subarray Problem (p68)
    - brute force solution - new notation? (p69)
        Ω(n^2) time
    - transformation -
        maximum subarray - nonempty, contiguous
        subarray whose values have the largest sum
    - divide & conquer -
        maximum subarray must lie in one of these
        after dividing into 2 different arrays:
    A[low:mid], low ≤ i ≤ j ≤ mid
    A[mid+1:high], mid ≤ i ≤ j ≤ high
    "crossing the midpoint" low ≤ i ≤ mid < j ≤ high
        (function on p71)
    "find_max_crossing_subarray"
        (function on p72)
(n choose k) notation seems to be Θ(n^2) time

Ch4.2
Strassen's' algorithm for matrix multiplication
    A = a_ij = n*n matrix
    B = b_ij = n*n matrix
    C = A*B
        c_ij = Σ a_ik*b_kj
    "square_matrix_multiply" function on (p75)
    "square_matrix_multiply_recursive" on (p77)
index calculations - identify a submatrix by a range
        of row indices and a range of column indices
Θ/asymptotic notation subsumes constant factors
        (except for recursive calls/T(n)notation?)

Strassen's' Method on (p79)
(1) Divide input matrices A, B and output matrix C
        into n/2 x n/2 submatrices
        (takes Θ(1) time )
(2) Create 10 submatrices, each of which is n/2 x n/2
        and is the sum/difference of two matrices
        created in step 1
        (all 10 created in Θ(n²) time )
(3) Recursively compute 7 matrix products (P_i) using
        matrices from step 1 & 2
        (size n/2 x n/2)
(4) Compute desired submatrices C_11, C_12, C_21, C_22
        of the result matrix C by adding and subtracting
        "various combinations" of the P_i matrices
        (all 4 submatrices computed in Θ(n^2) time)

Ch4.3
Mathematical Induction method (4 steps):
(1) Show true for n=1
(2) Assume true for n=k (mathematical inductin assumption)
(3) Prove/show true for n=k+1
(4) Restate as true by process of mathematical induction

(CLRS uses "strong" induction)
substitution method - for solving recurrences
(1) Guess the form of the solution
(2) Use mathematical induction to find the constants
        and show the solution works


    - showing the boundary conditions are suitable
        as base cases for inductive proof
    - gradually lower upper bound, raise lower bound
        until correct asymptotically tight solution

subtleties - sometimes the "guess" is correct,
        but the math fails
    mathematical induction does not work unless
        we prove the EXACT form of the inductive
        hypothesis (does need to be exact)
        (if this fails, does not prove it false)
    (1) revise the guess by subtracting lower order
        terms (p85)
        (inequalites become equalities?)
avoiding pitfalls (p86) - example 4.19?

changing variables - condensing variables into a
        more easily factorable term

Ch4.4
recursion tree - best used to generate a "good guess"
        and as a direct proof of a solution to a
        recurrence
    - each node represents the cost of
        a single subproblem
    - sum the costs within each tree level to
        obtain a set of per-level costs
    - then sum all per-level costs to determine
        total cost of all levels

"good guess" method (p89):
(tolerable sloppiness)
    - focus on finding an upper bound (floors and 
        cielings don't matter)
    - implied constant coefficient c>0
    - assume n is an exact power of (something)
        so that all subproblem sizes are integers
(a) create a tree with T(n)
(b) expand into an equivalent tree representing
        the recurrence
(c) continue expanding each tree node by breaking
        it into its constituent parts
        (expands until the result of the formula
        inside T(n) reduces to its base case)
(d) add up costs over all levels to determine the
        cost for the entire tree
(e) substitution method to verify guess is correct
    
    - expect the solution to be at most the number
        of levels times the cost of each level

Ch4.5
master method - "cookbook" method to solve
        recurrences of the form:
T(n) = a*T(n/b) + f(n)
        (a≥1 and b>1 are constants,
        f(n) is an asymptotically positive function)
need to memorize 3 cases to solve recurrences easily
(important things to note:
    n/b, a, b, are positive constants)

Theorem 4.1(Master Theorem)
    Let a≥1 and b>1 be constants,
    let f(n) be a function,
    let T(n) be defined on the nonnegative integers
        by the recurrence:
T(n) = a*T(n/b) + f(n)
        (where n/b is either floor(n/b) or ciel(n/b))
Then T(n) has the following asymptotic bounds:
(1) If f(n) = O(n^(log_b(a-ε))) for some constant ε>0,
        then T(n) = Θ(n^(log_b(a)))
(2) If f(n) = Θ(n^(log_b(a))),
        then T(n) = Θ(n^(log_b(a))*log_2(n))
(3) If f(n) = Ω(n^(log_b(a+ε))) for some constant ε>0,
        and if a*f(n/b)≤c*f(n) for some constant c<1
        and all sufficiently large n,
        then T(n) = Θ(f(n))

note:(p95)
The 3 cases dont cover all the possibilites for f(n)
    - gap between (1) and (2) when f(n) is smaller
        than n^(log_b(a)), but not polynomially
        smaller
    - gap between (2) and (3) when f(n) is larger
        than n^(log_b(a)), but not polynomially
        larger
(if f(n) falls into either of these gaps,
 or the regularity condition in case (3) fails
 then you can't' use the master method)
