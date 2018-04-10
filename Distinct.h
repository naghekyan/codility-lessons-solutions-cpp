//
//  Distinct.h
//  Test
//
//  Created by Narek Aghekyan on 4/3/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef Distinct_h
#define Distinct_h

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
    set<int> unique;
    for (auto elem : A)
    {
        unique.insert(elem);
    }
    
    return static_cast<int>(unique.size());
}

#endif /* Distinct_h */
