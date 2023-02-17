
Aim of the book:
    develop algorithms
    show they give correct answers
    understand their efficiency
----------------------------------------------------
1.1
algorithm - any well-defined computational
            procedure that takes some value as
            input, and produces some value as output
          - tool for solving computational problems
          - correct only if it halts with correct
            output
          - incorrect algorithms can be useful if error
            rate can be controlled (ch 31)

Sorting problem:
input  - a sequence of n numbers (a1, a2, ... , an)
output - reordering of input sequence such that
         a1' <= a2' <= ... <= an'

data structures - way to store and organize data
        in order to facilitate access and modifications

NP-complete problem - no known efficient algorithm to
        solve the problem, but no proof exists to show
        that an efficient algorithm doesn't exist
        - several NP-complete problems are similar to
        problems with known algorithms, can be used
        to approximate answers

parallelism - "multithreaded" algorithms take advantage
        of multiple cores (ch 27)
        - differs from "sequential" algorithms which
        use only a single corez

efficiency - the time it takes differing algorithms
        to solve a problem
        - usually measured as the most significant
        factor applied to the algorithm
        (lg n, n^2, etc...)
