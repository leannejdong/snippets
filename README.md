# Algorithms

##  Path finding

* [A* version1](https://godbolt.org/z/fEffWc)
* [A* better](https://godbolt.org/z/zW3z4q)
* [DFS](https://godbolt.org/z/ev9aKf)

## Dynamic Programming

Dynamic Programming is similar to backtracking except that we stop making redundant computations (i.e. Memoization. Calculate the answer to each subproblem only  once)

* [climb stairs](https://gcc.godbolt.org/z/3orrYE)
* [Knapsack](https://godbolt.org/z/7hWj3d)
* [Fibonacci-DP-vs-iteration](https://gcc.godbolt.org/z/67KPvf)

## Backtracking

The algorithm begins with anempty solution and extends the solution step by step. The search recursively goes through all different ways 
how a solution can be constructed.
[climb-stairs](https://gcc.godbolt.org/z/fdcdzf)

(https://gcc.godbolt.org/z/aK8jzT)

## NQueens

Find a way to place n queens on an nxn chessboard so that no two queens are attacking each other.

[NQueens by recursion](https://gcc.godbolt.org/z/PqP1ro)

## Hash Tables

## Graph algorithms

[Dijkstra's SSSP](https://gcc.godbolt.org/z/GP9xMa)

### Branch and Bound 

BB is an optimization algorithm converts a maximization into a minimization problem.

* [Travelling Sale Man](https://godbolt.org/z/9h95c4)
* [Test of Travelling Sale Man](https://godbolt.org/z/dq5vq7)
* [TSP via unique ptr](https://godbolt.org/z/nE5anv)

### Brute-force branch and bound

* [dynamic programming solution with O(n*2^n)](https://gcc.godbolt.org/z/hxzx9h)

# Useful Snippets

* [bitmap](https://gcc.godbolt.org/z/Pbfqzq)

* [bitset]( https://gcc.godbolt.org/z/5Mv8zo)

## Finite Difference with functor

* [simple](https://gcc.godbolt.org/z/E9WEbv)
* [template](https://gcc.godbolt.org/z/dx9KvE)
* [template (multi)](https://gcc.godbolt.org/z/4a18EP)
* [template (type_traits)](https://gcc.godbolt.org/z/xPTKj6)

## C++ general

* [padding and alignment](https://gcc.godbolt.org/z/ndscGM)
* [higer order function](https://godbolt.org/z/KKTeTT)
* [function object](https://godbolt.org/z/P65rEv)
* [when do u still need macros?](https://godbolt.org/z/M4Kaf3)
* Should you use raw or unique ptr?

  * [Example1](https://godbolt.org/z/qfo6dj)

  * [Example2](https://godbolt.org/z/fGWz9a)

  * [Example3](https://godbolt.org/z/Pqshfj)

* [non-owning pointer](https://godbolt.org/z/95s4Kq)
