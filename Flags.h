//
//  Flags.h
//  Test
//
//  Created by Narek Aghekyan on 4/9/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef Flags_h
#define Flags_h


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


int solution(vector<int> &A)
{
    // Using Golden Solution from here: https://codility.com/media/train/solution-flags.pdf
    const int size = static_cast<int>(A.size());
    vector<bool> isPeak(size, false);
    vector<int> nextPeakIndex(size, -1); // -1 means no next peak index is available for index `i`
    
    for (int i = 1; i < size - 1; ++i)
    {
        if (A[i] > max(A[i - 1], A[i + 1]))
        {
            isPeak[i] = true;
        }
    }
    
    for (int i = size - 2; i >= 0; --i)
    {
        nextPeakIndex[i] = isPeak[i] ? i : nextPeakIndex[i + 1];
    }
    
    // If we take `k` flags, every flag should be placed no closer than after `lastPlacedPos + k`
    // indicies which means that we need to divide interval to slices with size equal to `k`
    // evey interval can be devided to max sqrt(N) slices, therefore if we look from 1 to sqrt(N)+1
    // then we will loop through all possible flag counts that we could take with us, but we still
    // need to find out if we can place them succesffuly. Let's see by using greedy algorithm.
    
    int maxFlagCount = 0;
    const int maxPossibleFlagCount = floor(sqrt(size)) + 1;
    
    // NOTE: here we could use bisection algrithm (binary search) too
    for (int takenFlagCount = 1; takenFlagCount <= maxPossibleFlagCount; ++takenFlagCount)
    {
        int position = 0;
        int placedFlagCount = 0;
        
        while (position < size && placedFlagCount < takenFlagCount)
        {
            position = nextPeakIndex[position];
            
            // no more peaks available
            if (position == -1)
            {
                break;
            }
            else
            {
                ++placedFlagCount;
                position += takenFlagCount;
            }
        }
        
        maxFlagCount = max(maxFlagCount, placedFlagCount);
    }
    
    return maxFlagCount;
}

#endif /* Flags_h */
