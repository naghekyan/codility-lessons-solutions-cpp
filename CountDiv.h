//
//  CountDiv.h
//  Test
//
//  Created by Narek Aghekyan on 3/30/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef CountDiv_h
#define CountDiv_h

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



int solution(int A, int B, int K) {
    /*
     version 1
     const int firstDividableInRange = A % K == 0 ? A : A + (K - A % K);
     const int lastDividableInRange = B - B % K;
     const int result = (lastDividableInRange - firstDividableInRange) / K + 1;
     */
    
    // version 2
    return B / K - A / K + (A % K == 0 ? 1 : 0);
}

#endif /* CountDiv_h */
