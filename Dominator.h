//
//  Dominator.h
//  Test
//
//  Created by Narek Aghekyan on 4/6/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef Dominator_h
#define Dominator_h

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
    int dominatorCandidate = 0;
    int dominationCount = 0;
    
    // removing two different elements does not change the array leader (see here: https://codility.com/media/train/6-Leader.pdf)
    for (auto elem : A)
    {
        if (dominationCount == 0)
        {
            dominatorCandidate = elem;
            ++dominationCount;
        }
        else
        {
            dominationCount += (elem == dominatorCandidate) ? 1 : -1;
        }
    }
    
    int dominatorCandidateIndex = -1;
    int dominatorCandidateCount = 0;
    for (int i = 0; i < size; ++i)
    {
        if (A[i] == dominatorCandidate)
        {
            dominatorCandidateIndex = i;
            ++dominatorCandidateCount;
        }
    }
    
    return (dominatorCandidateCount > size / 2) ? dominatorCandidateIndex : -1;
}

#endif /* Dominator_h */
