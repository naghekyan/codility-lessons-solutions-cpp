//
//  FrogRiverOne.h
//  Test
//
//  Created by Narek Aghekyan on 3/29/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef FrogRiverOne_h
#define FrogRiverOne_h

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

int solution(int X, vector<int> &A)
{
    unordered_set<int> positions;
    
    for (int i = 0; i < A.size(); ++i)
    {
        const int pos = A[i];
        if (pos <= X)
        {
            positions.insert(pos);
            if (positions.size() == X)
            {
                return i;
            }
        }
    }
    
    return -1;
}

#endif /* FrogRiverOne_h */
