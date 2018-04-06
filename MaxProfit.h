//
//  MaxProfit.h
//  Test
//
//  Created by Narek Aghekyan on 4/6/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef MaxProfit_h
#define MaxProfit_h

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
    int minimum = numeric_limits<int>::max();
    int maxProfit = 0;
    
    for (int i = 0; i < size; ++i)
    {
        minimum = min(minimum, A[i]);
        maxProfit = max(maxProfit, A[i] - minimum);
    }
    
    return maxProfit;
}

#endif /* MaxProfit_h */
