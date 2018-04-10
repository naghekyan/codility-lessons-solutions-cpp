//
//  OddOccurrencesInArray.h
//  Test
//
//  Created by Narek Aghekyan on 3/28/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef OddOccurrencesInArray_h
#define OddOccurrencesInArray_h

#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;


int solution(vector<int> &A)
{
    std::unordered_map<int, int> valuesToCount;
    
    for (auto elem : A)
    {
        valuesToCount[elem]++;
    }
    
    int result = 0;
    for (auto elem : valuesToCount)
    {
        if (elem.second % 2 != 0)
        {
            result = elem.first;
            break;
        }
    }
    
    return result;
}

#endif /* OddOccurrencesInArray_h */
