//
//  FrogJmp.h
//  Test
//
//  Created by Narek Aghekyan on 3/29/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef FrogJmp_h
#define FrogJmp_h

#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

int solution(int X, int Y, int D)
{
    return std::ceil(static_cast<double>(Y - X) / D);
}

#endif /* FrogJmp_h */
