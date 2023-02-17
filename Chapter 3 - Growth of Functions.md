```py

Ch3.1
asymptotic efficiency - how the running time of an
        algorithm increases with the size of input
        "in the limit" - size increases w/o bound
-   in this chapter, Θ(n), O(n), o(n), Ω(n), ω(n),
        all mean they ARE the upper/lower bounds

asymptotic notation:
Θ-notation - asymptotically bounds a function from
        above _and_ below
    For a function g(n), we denote by Θ(g(n)) the set
        of functions:
    Θ(g(n)) = {f(n): there exist positive constants
                     c1, c2, and n0 such that
        0 <= c1*g(n) <= f(n) <= c2*g(n) for all n>=n0}
    : - colon means "such that"
    - a function f(n) belongs to the set Θ(g(n)) if
        there exist positive constants c1 and c2 such
        that it can be "sandwiched" between c1*g(n)
        and c2*g(n) for sufficiently large n
    f(n) ∈ Θ(g(n)) is the same as f(n) = Θ(g(n))
    Θ(g(n)) requires that every member f(n) ∈ (g(n))
        be asymptotically non-negative

asymptotically tight bound - for all n >= n0, the
        function f(n) is equal to g(n) to within
        a constant factor
    - meaning, there are greater/lesser polynomial 
        functions that can be used as an upper/lower
        bound, but the tight bounds only refer to
        those closest to the original function
asymptotically non-negative - f(n) must be
        non-negative whenever n is sufficiently large
    - assume every function used in Θ notation is
        asymptotically non-negative,
        or else the set Θ(g(n)) is empty
asymptotically positive - positive for all
        sufficiently large n
Θ(n^0) == Θ(1) - any constant is a degree-0 polynomial
        - any constant can be expressed like this

O-notation (big O) - asymptotically tight _upper_ bound
        (asymptotic upper bound)
    O(g(n)) = {f(n): there exist positive constants
                     c and n0 such that
               0 <= f(n) <= c*g(n) for all n >= n0}
    f(n) = O(g(n)) implies f(n) = Θ(g(n))
        Θ(g(n)) ⊆ O(g(n))
    O(n^2) running time - there is a function f(n),
        that is O(n^2) such that for any value n,
        the running time on the input is bounded
        from above by the value f(n)
        - worst case running time is O(n^2)

Ω-notation - "big-omega"
        - provides an asymptoticly tight _lower_ bound
        Ω(g(n)) = {f(n: there exist positive constants
                   c and n0 such that
            0 <= c*g(n) <= f(n) for all n > n0)}
    Theorem 3.1
    For any two functions f(n) and g(n),
        we have f(n) = Θ(g(n)) if and only if
        f(n) = O(g(n)) and f(n) = Ω(g(n))
    - usually used to prove asymptotically tight
        bounds from asymptotic upper and lower bounds
    - if running time (no modifier) of an algorithm
        is Ω(g(n)), no matter what what input size n,
        running time is at least a constant * g(n)
        (for sufficiently large n)

rule for interpreting asymptotic notation on the
        left hand side of an equation
    (p50) - No matter how the anonymous functions are
        chosen on the left of the equal sign, there
        is a way to choose the anonymous functions on
        the right of the equal sign to make the
        equation valid
        (right hand side provides courser detail)

o-notation (little-o) - used to denote an upper bound
        that is _not_ asymptotically tight
    o(g(n)) = {f(n): for any positive constant c>0,
            there exists a constant n0 > 0 such that
        0 <= f(n) < c*g(n) for all n >= n0}
    for big-O notation, the bound holds for _some_
        constant c>0, but
    for little-o notation, the bound holds for _ALL_
        constants c>0
    g(n) will always be larger than f(n):
    lim(n->∞)(f(n)/g(n)) = 0

ω-notation (little-Ω) - denotes a lower bound that
        is _not_ asymptotically tight
    f(n) ∈ ω(g(n)) if and only if g(n) ∈ o(f(n))
    ω(g(n)) = {f(n): for any positive constant c > 0,
            there existsw a constant n0 > 0 such that
        0 <= c*g(n) < f(n) for all n > = n0}
    lim(n->∞)(f(n)/g(n)) = ∞


(p51-52)
Transitivity
Reflexivity
Symmetry
Transpose Symmetry
Trichotomy

3.2 Standard notations and common functions
monotonically increasing - a function that
        doesn't decrease (can be flat)
    m <= n implies f(m) <= f(n)
monotonically decreasing - a function that
        doesn't increase (can be flat)
    m <= n implies f(m) >= f(n)
strictly increasing - function is always increasing
    m < n implies f(m) < f(n)
strictly decreasing - function is always decreasing
    m < n implies f(m) > f(n)

polylogarithmically bounded - bounded by a logarithm?
    f(n) = O(lg^k(n))
