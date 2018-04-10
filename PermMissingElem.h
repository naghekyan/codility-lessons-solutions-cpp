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

int solution(vector<int> &A)
{
    const long long size = static_cast<long long>(A.size());
    const long long sum = accumulate(A.begin(), A.end(), 0L);
    const long long arithmeticProgressionSum = (1 + (size + 1)) * (size + 1) / 2;
    return arithmeticProgressionSum - sum;
}

#endif /* PermMissingElem_h */
