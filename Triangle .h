//
//  Triangle .h
//  Test
//
//  Created by Narek Aghekyan on 4/3/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef Triangle__h
#define Triangle__h

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
using namespace std;

int solution(vector<int> &A)
{
    const int size = static_cast<int>(A.size());
    
    if (size < 3)
    {
        return 0;
    }
    
    sort(A.begin(), A.end());
    for (int i = 0; i < size - 2; ++i)
    {
        if (A[i] > A[i + 2] - A[i + 1]) // the same as A[i] + A[i + 1] > A[i + 2] but will not overflow for 3 MAX_INTs
            return 1;
    }
    
    return 0;
}

#endif /* Triangle__h */
