//
//  PermCheck.h
//  Test
//
//  Created by Narek Aghekyan on 3/29/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef PermCheck_h
#define PermCheck_h

#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(vector<int> &A)
{
    unordered_map<int, int> valueToCount;
    int max = 0;
    
    for (auto elem : A)
    {
        max = std::max(max, elem);
        valueToCount[elem]++;
        
        if (valueToCount[elem] != 1)
        {
            return 0;
        }
    }
    
    return (max > valueToCount.size()) ? 0 : 1;
}

#endif /* PermCheck_h */
