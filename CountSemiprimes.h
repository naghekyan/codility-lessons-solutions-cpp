//
//  CountSemiprimes.h
//  Test
//
//  Created by Narek Aghekyan on 4/11/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef CountSemiprimes_h
#define CountSemiprimes_h

#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <functional>
#include <stack>
#include <queue>
#include <random>
using namespace std;

// Sieve of Eratosthenes (see here: https://codility.com/media/train/9-Sieve.pdf)
vector<bool> getIsPrimeVec(const int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    /*
     Notice that we needn’t cross out (mark as non-prime) multiples of `i` which are less than `i * i`.
     Such multiples are of the form `k * i`, where `k < i`. These have already been removed by one of
     the prime divisors of `k` (during previous iterations). In its turn, this means that the algorithm
     is allowed to terminate its iteration when `i * i` is greater than `n`. Hence the loop below has `limit`.
     */
    
    const int limit = floor(sqrt(n)) + 1;
    
    int i = 2;
    while (i <= limit)
    {
        if (isPrime[i])
        {
            int k = i * i;
            while (k <= n)
            {
                isPrime[k] = false;
                k += i;
            }
        }
        ++i;
    }
    
    return isPrime;
}

vector<int> getSmallestPrimeFactor(const int n)
{
    vector<int> smallestPrimeFactor(n + 1, 0);
    
    const int limit = floor(sqrt(n)) + 1;
    
    int i = 2;
    while (i <= limit)
    {
        if (smallestPrimeFactor[i] == 0)
        {
            int k = i * i;
            while (k <= n)
            {
                if (smallestPrimeFactor[k] == 0)
                {
                    smallestPrimeFactor[k] = i;
                }
                k += i;
            }
        }
        
        ++i;
    }
    
    return smallestPrimeFactor;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q)
{
    vector<bool> isPrime = getIsPrimeVec(N);
    vector<int> smallestPrimeFactor = getSmallestPrimeFactor(N);
    
    vector<int> prefixSum(N + 1, 0);
    
    for (int i = 1; i <= N; ++i)
    {
        int count = 0;
        const int primeFactor = smallestPrimeFactor[i];
        if (primeFactor != 0)
        {
            const int otherFactor = i / primeFactor;
            if (isPrime[otherFactor])
            {
                count = 1;
            }
        }
        prefixSum[i] = count + prefixSum[i - 1];
    }
    
    const int size = static_cast<int>(P.size());
    vector<int> result(size, 0);
    for (int i = 0; i < size; ++i)
    {
        const int rangeStart = P[i];
        const int rangeEnd = Q[i];
        
        result[i] = prefixSum[rangeEnd] - prefixSum[rangeStart - 1];
    }
    
    return result;
}

#endif /* CountSemiprimes_h */
