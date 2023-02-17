```py

Ch11.1
hash table - data structure for implementing
    dictionaries
    - worst case Θ(n) time
    - average case (w/some assumptions) O(1) time
    - uses array size proportional to the number
        of keys stored
    - array index is computed from the key

direct address table - an array in which each
        position/slot corresponds to a key
        (in the universe U?)
    - works well when the "universe" of keys is small

--dictionary operations (254)
Direct_Address_Search(T,k)
Direct_Address_Insert(T,x)
Direct_Address_Delete(T,x)

Ch11.2
problem w/direct address table: 
    - if "universe" of keys is too large,
        the memory footprint would be too large
        compared to the actual table being stored,
        and most of the space is wasted
    - key k is stored in slot k

hash table requires much less storage (when keys
        are stored in a dictionary much smaller
        than the "universe" of possible keys)
    - storage requirement Θ(|K|)
    - searching requirement O(1) time
hash function - key k is stored in slot h(k)
    - where the hash function is used to compute
        the slot index from the key value
    - "h" maps the universe "U" (i think by this
        they mean the largest key value?)
        of keys into the slots of a
        "hash table" T[0:m-1]
    - where the size of the hash table is
        much less than |U|
    - h:U -> {0,1,...,m-1}
    - (k hashes to slot h(k))
collision - two keys may hash to the same slot
    - deterministic (given input k should always
        produce the same output)

chaining - used for collision resolution
    - place all elements that hash to the same
        slot into a linked list based on that slot
    - slot contains a pointer to the head of that
        list (if none, slot contains NULL)

(p258)
Chained_Hash_Insert(T,x)
Chained_Hash_Search(T,k)
Chained_Hash_Delete(T,x)

doubly linked list - delete item quickly
singly linked list - must find x in the list
        T[h(x.key)] so that the "next" attribute
        of the predecessor can be updated

load factor(α) - average number of elements in chain
    - for table T = n/m (m=slots, n=elements)
    - α is evaluated in relation to 1?

average-case performance depends on how well the
        hash function distributes the set of keys
        to be stored among the slots (on average)
simple uniform hashing - any given element is
        equally likely to hash to any slot,
        independently of where any other element
        has hashed to

Theorem 11.1 - In a hash table in which collisions
        are resolved by chaining, an "unsuccessful"
        search takes average-case time Θ(1+α)

Theorem 11.2 - In a hash table in which collisions
        are resolved by chaining, a "successful"
        search takes average-case time Θ(1+α)
    (under the assumption of simple uniform hashing)

    - if number of slots is at least proportional
        to the number of elements in the table,
        n = O(m)
        α = n/m = O(m)/m = O(1)
    - searching takes constant time on average
    - all dictionary operations average O(1) time

Ch11.3
hashing schemes
heuristic - division/multiplication
universal hashing - randomization

simple uniform hashing - keys are random real
        numbers, independently & uniformly
        distributed in range 0≤k<1
    - h(k) = floor(k*m)
radix notation? - multiply letters by their decimal
        values

division method - map a key into a slot by taking
        the remainder of key/slots
    h(k) = k*mod(m)     k=keys, m=slots (fast?)
    - m cannot be a power of 2, or else it's
        just the lowest order bits of k?
    - m can be "a prime not too close to an exact
        power of 2"

multiplication method - 2 steps
    (1) multiply key by a constant A: 0<A<1
        and extract the fractional part of result
    (2) multiply result by number of slots m
        and take the floor of the result
    h(k) = floor(m*(k*A*mod(1)))
        (k*A*mod(1) == k*A-floor(k*A) to just get
        the fractional part)
    - one advantage: value of m is not critical??
    - typically m is a power of 2

universal hashing - choose a hash function
        randomly in a way that is independent
        of the keys being stored
    - used to prevent exploiting fixed hash function
    - randomizing input guarantees no single input
        will evoke worst case behavior

Theorem 11.3 (p265)
- if key is '_NOT_' in the table, expected length
    of the list the key hashes to is at most 
    the load factor α = n/m
- if key '_IS_' in the table, expected length
    is at most 1+α

Corollary 11.4 (266)
- Θ(n) expected running time for any sequence of
        n Insert, Search, Delete operations
        containing O(m) Insert operations

universal class of hash functions: (p267)
- h_ab(k) = (a*k+b)mod(p)mod(m)
    - p is prime number large enough to hold all keys
    - a is a random number 1 ≤a< p
    - b is a random number 0 ≤b< p

Ch11.4
open addressing - all elements occupy the hash table
    - each table entry has either an element of NULL
        (no pointers or linked lists)
    - hash table can fill up
    - load factor α can never exceed 1
    - compute the sequence of slots
- insertion by probing until empty slot is found
    - sequence of slots probed is based on the key
    - extend the hash function to include the
        probe attempt number (starting from 0)
- probe sequence - includes a permutation of the
        probe number as a "salt" for the key

Hash_Insert(T,k) (p270)
Hash_Search(T,k)

- deleting is difficult?
    - mark the slot a special Deleted value
    - modify Hash_Insert to recognize the value
    - chaining more common with this?

uniform hashing - probe sequence of each key is
        equally likely to be any of m! permutations
        of the slot numbers
    - hash function produces not just a hash number,
        but a whole sequence
    - 3  techniques: linear probing
                     quadratic probing
                     double hashing

auxiliary hash function - an extra (but ordinary)
        hash function used in this hash function

linear probing - uses hash function:
    h(k,i) = (h`(k)+i)mod(m)
    (h` is an auxiliary hash function)
- primary clustering - long runs of occupied
        slots build up, increasing search time

quadratic probing - uses hash function:
    h(k,i) = (h`(k)+c_1*i+c_2*i)*mod(m)
    (h` is an auxiliary hash function)
- secondary clustering = milder than primary clustering

double hashing - uses hash function:
    h(k,i) = (h_1(k)+i*h_2(k)*mod(m))
    (h_1 & h_2 are auxiliary hash functions)
    - initial probe position & offset may vary
    - h_2(k) must be relative prime to the
        hash-table size m
    - let m be a power of 2 and design h_2 to
        always produce an odd number

Theorem 11.6
- load factor α =n/m< 1
- expected number of probes in unsuccessful search
        is at most 1/(1-α) (assuming uniform hashing)

Corollory 11.7
- inserting an element into an open-address hash
        table w/load factor α requires at most
        1/(1-α) probes on average

Theorem 11.8
- open-address hash table w/load factor α has
    expected number of probes in a successful
    search is at most
    (1/α)*ln(1/(1-α))

Ch11.5
static - once keys are in the table, the set of
        keys never changes
perfect hashing - O(1) memory accesses required
        for a search in the worst case
    - uses 2 levels of universal hashing
- 1st level - normal hashing (no chaining)
- 2nd level - small secondary hash table w/associated
        hash function
    - size m of secondary hash table needs to be
        the square of the number of keys hashing
        to the same? slot
    - hash function can be chosen to limit the size

Theorem 11.9
- for n keys in hash table of size m=n² using
        universal hash function:
    - collision probability is less than 1/2

Theorem 11.10
- n keys, size m=n, hash function h:
    - Expectation? < 2*n
    - size ≥ 4*n
