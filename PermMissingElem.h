//
//  PermMissingElem.h
//  Test
//
//  Created by Narek Aghekyan on 3/29/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef PermMissingElem_h
#define PermMissingElem_h

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

int solution(vector<int> &A) {
    unordered_set<int> values;
    for (int i = 1; i <= A.size() + 1; ++i)
    {
        values.insert(i);
    }
    
    for (auto elem : A)
    {
        auto it = values.find(elem);
        values.erase(it);
    }
    
    return *(values.begin());
}

#endif /* PermMissingElem_h */
