//
//  Fish.h
//  Test
//
//  Created by Narek Aghekyan on 4/5/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef Fish_h
#define Fish_h

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

struct Fish
{
    int size;
    bool isMovingDownstream;
};

bool isEating(const Fish& upstreamFish, const Fish& downstreamFish)
{
    return upstreamFish.isMovingDownstream && !downstreamFish.isMovingDownstream;
}

bool isUpstreamFishEaten(const Fish& upstreamFish, const Fish& downstreamFish)
{
    return isEating(upstreamFish, downstreamFish) && upstreamFish.size < downstreamFish.size;
}

void checkFishEating(stack<Fish>& upstreamFishes, const Fish& downstreamFish)
{
    // upstream ------f1---f2---f3------------------------> downstream
    // downstream fish can eat lots of smaller fishes positioned upstream but moving downstream
    while (!upstreamFishes.empty() && isUpstreamFishEaten(upstreamFishes.top(), downstreamFish))
    {
        upstreamFishes.pop();
    }
    
    if (upstreamFishes.empty() || !isEating(upstreamFishes.top(), downstreamFish))
    {
        upstreamFishes.push(downstreamFish);
    }
}

int solution(vector<int> &A, vector<int> &B)
{
    stack<Fish> fishes;
    const int size = static_cast<int>(A.size());
    
    for (int i = 0; i < size; ++i)
    {
        const int currentFishSize = A[i];
        const bool isCurrentFishMovingDownstream = B[i];
        const Fish downstreamFish{currentFishSize, isCurrentFishMovingDownstream};
        
        if (fishes.empty())
        {
            fishes.push(downstreamFish);
        }
        else
        {
            checkFishEating(fishes, downstreamFish);
        }
    }
    
    return static_cast<int>(fishes.size());
}

#endif /* Fish_h */
