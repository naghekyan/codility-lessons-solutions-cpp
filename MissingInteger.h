//
//  MissingInteger.h
//  Test
//
//  Created by Narek Aghekyan on 3/29/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef MissingInteger_h
#define MissingInteger_h

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
    
    for (auto elem : A)
    {
        values.insert(elem);
    }
    
    int result = 1;
    while (values.find(result) != values.end())
    {
        ++result;
    }
    
    return result;
}

#endif /* MissingInteger_h */
