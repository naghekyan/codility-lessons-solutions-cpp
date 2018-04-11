//
//  Peaks.h
//  Test
//
//  Created by Narek Aghekyan on 4/11/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef Peaks_h
#define Peaks_h

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


int getIntervalCout(const int sliceSize, const int size, const vector<int>& nextPeakIndex)
{
    int position = 0;
    int sliceLeftBoundaryIndex = sliceSize - 1;
    int placedSliceCount = 0;
    
    while (position < size)
    {
        position = nextPeakIndex[position];
        
        const bool canPlaceFlagInCurrentSlice = position != -1 && position <= sliceLeftBoundaryIndex;
        if (canPlaceFlagInCurrentSlice)
        {
            ++placedSliceCount;
            position = sliceLeftBoundaryIndex + 1;
            sliceLeftBoundaryIndex += sliceSize;
        }
        else
        {
            placedSliceCount = 0;
            break;
        }
    }
    
    return placedSliceCount;
}

int solution(vector<int> &A)
{
    // NOTE: this solution is not O(N logN logN) but is passes the checks 100%.
    // NOTE: See https://stackoverflow.com/questions/20886486/codility-peaks-complexity for better solution
    
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
    
    int maxSliceCount = 0;
    const int maxPossibleSliceCount = floor(sqrt(size)) + 1;
    
    for (int i = 1; i <= maxPossibleSliceCount; ++i)
    {
        if (size % i != 0)
        {
            continue;
        }
        
        // let's see if we can place `sliceCount` number of flags - one in each slice
        const int sliceSize1 = i;
        const int sliceSize2 = size / i;
        
        const int placedSliceCount1 = getIntervalCout(sliceSize1, size, nextPeakIndex);
        const int placedSliceCount2 = getIntervalCout(sliceSize2, size, nextPeakIndex);
        const int placedSliceCount = max(placedSliceCount1, placedSliceCount2);
        
        maxSliceCount = max(maxSliceCount, placedSliceCount);
    }
    
    return maxSliceCount;
}

#endif /* Peaks_h */
