//
//  MinPerimeterRectangle .h
//  Test
//
//  Created by Narek Aghekyan on 4/9/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef MinPerimeterRectangle__h
#define MinPerimeterRectangle__h

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
    
    int minPerimeter = numeric_limits<int>::max();
    int i = 1;
    const int limit = ceil(sqrt(N));
    
    while (i <= limit)
    {
        if (N % i == 0)
        {
            const int a = i;
            const int b = N / i;
            const int perimeter = 2 * (a + b);
            minPerimeter = min(minPerimeter, perimeter);
        }
        ++i;
    }
    
    return minPerimeter;
}

#endif /* MinPerimeterRectangle__h */
