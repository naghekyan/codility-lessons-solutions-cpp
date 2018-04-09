//
//  CountFactors.h
//  Test
//
//  Created by Narek Aghekyan on 4/9/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef CountFactors_h
#define CountFactors_h

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


int solution(int N)
{
    // see solution explanation here: https://codility.com/media/train/8-PrimeNumbers.pdf
    int count = 0;
    int i = 1;
    const int limit = ceil(sqrt(N));
    
    while (i < limit)
    {
        if (N % i == 0)
        {
            count += 2;
        }
        ++i;
    }
    
    return (i * i == N) ? ++count : count;
}


#endif /* CountFactors_h */
