// There are N <= 5000 workers. Each is available during
// some days of this month. Find two workers with maximum 
// intersection of their schedules
// Hint: Intersection of two workers is just bitwise&
// between two numbers and can be computed in constant time, this way we get rid of D
// The complexity will be O(N*N). The whole solution is first change every set
// into a binary number stored as a single int. Iterate over all pairs of workers,
// for each of them compute bitwise&, and in their bitwise&, we need the number of ones

#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

constexpr int MAX_D = 30;
constexpr int MAX_N = 365;

std::bitset<MAX_D> x[MAX_N];
int intersection(int i, int j)
{
    return(x[i] & x[j]).count();
}

int main()
{
    intersection(10, 20);
}

