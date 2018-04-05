//
//  StoneWall.h
//  Test
//
//  Created by Narek Aghekyan on 4/5/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef StoneWall_h
#define StoneWall_h

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
#include <functional>
#include <stack>
#include <queue>
using namespace std;


int solution(vector<int> &H)
{
    stack<int> bricksConsistingBaseWalls;
    int currentWallHeight = 0;
    int usedBrickCount = 0;
    
    for (auto elem : H)
    {
        while (elem < currentWallHeight)
        {
            const int latestAddedBase = bricksConsistingBaseWalls.top();
            bricksConsistingBaseWalls.pop();
            currentWallHeight -= latestAddedBase;
        }
        
        if (elem > currentWallHeight)
        {
            const int diff = elem - currentWallHeight;
            bricksConsistingBaseWalls.push(diff);
            ++usedBrickCount;
            currentWallHeight = elem;
        }
    }
    
    return usedBrickCount;
}

#endif /* StoneWall_h */
