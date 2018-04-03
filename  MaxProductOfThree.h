//
//   MaxProductOfThree.h
//  Test
//
//  Created by Narek Aghekyan on 4/3/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef _MaxProductOfThree_h
#define _MaxProductOfThree_h

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
    sort(A.begin(), A.end());
    
    return max(A[size - 3] * A[size - 2] * A[size - 1], // 3 last elements are positive or 3 last elements are negative or there are just 3 elements
               A[0] * A[1] * A[size - 1]); // a0 and a1 are negative, and last one is positive
}

#endif /* _MaxProductOfThree_h */
