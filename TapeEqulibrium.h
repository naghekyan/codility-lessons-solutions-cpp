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
using namespace std;


int solution(vector<int> &A) {
    const int sum = std::accumulate(A.begin(), A.end(), 0);
    std::set<int> diffs;
    
    int prevSum = A[0];
    for (int i = 1; i < A.size(); ++i)
    {
        int postSum = sum - prevSum;
        int diff = abs(prevSum - postSum);
        diffs.insert(diff);
        prevSum += A[i];
    }
    
    return *(diffs.begin());
}

#endif /* TapeEqulibrium_h */
