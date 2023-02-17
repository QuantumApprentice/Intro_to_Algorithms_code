```py

Ch5.1
Probability theory - Appendix C
probabilistic analysis - the use of probability in
        the analysis of problems
    - used to analyze the running time of an algorithm
        to help design an efficient algorithm (p116)
    - must use knowledge or/make assumptions about
        the distribution of the inputs
    - analyze the algorithm,
        compute average-case running time
        taking the average over the distribution
        of the possible inputs (not forced randomized)
average-case running time - running time averaged
        over all possible inputs
total order - "partial order that is also a total
        relation" in which any 2 elements are
        comparable
uniform random permutation - each of the possible
        n! permutations appears w/equal probability
randomized algorithm - behavior is determined by its
        input and values produced by a random-number
        generator
pseudorandom-number generator - deterministic
        algorithm returning numbers that "look"
        statistically random
expected running time - running time of a randomized
        algorithm
    - usually the mean/weighted mean
        (the algorithm itself enforces randomization)

Ch5.2
indicator random variable I{A} - convenient method
        to convert between probabilities
        and expectations
    Given a sample space S and an event A:
    I{A} = {1 if A occurs}
           {0 if A does not occur}
sample space (S) - the set whose elements are called
        elementary events (possible outcome)
event - subset of the sample space S
expected value (p1197) - summary of the distribution
        of a random variable is the "average" of
        the values it takes on
    E[x] = Σ(x*Pr{X=x})

Lemma 5.1
The expected value of an indicator random variable
        associated with an event A is equal to the
        probability that A occurs
    Given a sample space S and an event A in the
        sample space S,
    Let X_A = I{A}.
        Then E[X_A] = Pr{A}
    Proof (p119)

linearity of expectation = the expectation of two
        random variables is the sum of their
        expectations
    E[X+Y] = E[X] + E[Y]
