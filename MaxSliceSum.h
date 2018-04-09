//
//  MaxSliceSum.h
//  Test
//
//  Created by Narek Aghekyan on 4/9/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef MaxSliceSum_h
#define MaxSliceSum_h

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
#include<functional>
#include <stack>
#include <queue>
using namespace std;


// though O(N) time and memory complexity and satisfies the priblem limitations,
// but Kadane's algo takes O(1) memory so there is a better solution

/*
 int solution(vector<int> &A)
 {
 const int size = static_cast<int>(A.size());
 vector<long long> prefixSums(size, 0);
 
 prefixSums[0] = A[0];
 for (int i = 1; i < size; ++i)
 {
 prefixSums[i] = prefixSums[i - 1] + A[i];
 }
 
 long long minPrefixSumTillCurrent = 0;
 long long maxSliceSum = A[0];
 
 for (int i = 0; i < size; ++i)
 {
 maxSliceSum = max(maxSliceSum, prefixSums[i] - minPrefixSumTillCurrent);
 minPrefixSumTillCurrent = min(minPrefixSumTillCurrent, prefixSums[i]);
 }
 
 return static_cast<int>(maxSliceSum);
 }
 */


/* Kadane's algo (dynamic porogramming) - better solution O(N) time and O(1) memory complexity */
int solution(vector<int> &A)
{
    const int size = static_cast<int>(A.size());
    int maxSubArrayEndingOnI = A[0];
    int generalMaxSubArraySum = A[0];
    
    for (int i = 1; i < size; ++i)
    {
        maxSubArrayEndingOnI = max(A[i], maxSubArrayEndingOnI + A[i]);
        generalMaxSubArraySum = max(generalMaxSubArraySum, maxSubArrayEndingOnI);
    }
    
    return generalMaxSubArraySum;
}

#endif /* MaxSliceSum_h */
