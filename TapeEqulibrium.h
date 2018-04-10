//
//  TapeEqulibrium.h
//  Test
//
//  Created by Narek Aghekyan on 3/29/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef TapeEqulibrium_h
#define TapeEqulibrium_h

#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <limits>
using namespace std;


int solution(vector<int> &A)
{
    const int sum = std::accumulate(A.begin(), A.end(), 0);
    int minDiff = numeric_limits<int>::max();
    
    int prevSum = A[0];
    for (int i = 1; i < static_cast<int>(A.size()); ++i)
    {
        int postSum = sum - prevSum;
        int diff = abs(prevSum - postSum);
        minDiff = min(minDiff, diff);
        prevSum += A[i];
    }
    
    return minDiff;
}

#endif /* TapeEqulibrium_h */
