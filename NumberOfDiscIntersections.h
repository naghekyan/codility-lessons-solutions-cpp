//
//  NumberOfDiscIntersections.h
//  Test
//
//  Created by Narek Aghekyan on 4/4/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef NumberOfDiscIntersections_h
#define NumberOfDiscIntersections_h

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
using namespace std;

struct Edge
{
    long long coordinate; // to fit the range
    bool isLeftBoundary;
    
    bool operator<(const Edge& rhs) const
    {
        return coordinate < rhs.coordinate || (coordinate == rhs.coordinate && isLeftBoundary == true);
    }
};

int solution(vector<int> &A)
{
    const int size = static_cast<int>(A.size());
    
    vector<Edge> intervalEdges;
    
    for (int i = 0; i < size; ++i)
    {
        const long long center = static_cast<long long>(i);
        const long long radius = static_cast<long long>(A[i]);
        const long long left = center - radius;
        const long long right = center + radius;
        intervalEdges.push_back({left, true});
        intervalEdges.push_back({right, false});
    }
    
    sort(intervalEdges.begin(), intervalEdges.end());
    
    int startedButNotEndedIntervalCount = 0;
    int intersectionCount = 0;
    
    for (const auto& elem : intervalEdges)
    {
        const int isIntervalStarting = elem.isLeftBoundary;
        
        if (isIntervalStarting)
        {
            intersectionCount += startedButNotEndedIntervalCount;
            ++startedButNotEndedIntervalCount;
        }
        else
        {
            --startedButNotEndedIntervalCount;
        }
        
        if (intersectionCount > 1e7)
        {
            return -1;
        }
    }
    
    return intersectionCount;
}

#endif /* NumberOfDiscIntersections_h */
