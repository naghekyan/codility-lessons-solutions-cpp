//
//  MaxCounters.h
//  Test
//
//  Created by Narek Aghekyan on 3/29/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef MaxCounters_h
#define MaxCounters_h

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



vector<int> solution(int N, vector<int> &A)
{
    vector<int> counters(N, 0);
    int counterMaxValue = 0;
    int bias = 0;
    
    for (auto elem : A)
    {
        if (elem >= 1 && elem <= N)
        {
            const int index = elem - 1;
            const int value = counters[index];
            counters[index] = (value <= bias) ? bias + 1 : value + 1;
            counterMaxValue = max(counterMaxValue, counters[index]);
        }
        else if (elem == N+1)
        {
            bias = counterMaxValue;
        }
    }
    
    for (auto counter : counters)
    {
        if (counter < bias)
        {
            counter = bias;
        }
    }
    
    return counters;
}

#endif /* MaxCounters_h */
