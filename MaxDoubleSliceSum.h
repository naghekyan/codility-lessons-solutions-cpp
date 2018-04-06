//
//  MaxDoubleSliceSum.h
//  Test
//
//  Created by Narek Aghekyan on 4/6/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef MaxDoubleSliceSum_h
#define MaxDoubleSliceSum_h

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
    const int size = static_cast<int>(A.size());
    
    // Use Kadane’s algorithm from two directions
    vector<int> maxFromSecondElemToCurrent(size, 0);
    vector<int> maxFromPrelastElemToCurrent(size, 0);
    
    for (int i = 1; i < size; ++i)
    {
        maxFromSecondElemToCurrent[i] = max(0, maxFromSecondElemToCurrent[i - 1] + A[i]);
    }
    
    for (int i = size - 2; i >= 0; --i)
    {
        maxFromPrelastElemToCurrent[i] = max(0, maxFromPrelastElemToCurrent[i + 1] + A[i]);
    }
    
    int result = 0;
    for (int i = 1; i < size - 1; ++i)
    {
        result = max(result, maxFromSecondElemToCurrent[i - 1] + maxFromPrelastElemToCurrent[i + 1]);
    }
    
    return result;
}

#endif /* MaxDoubleSliceSum_h */
