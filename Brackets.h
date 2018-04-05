//
//  Brackets.h
//  Test
//
//  Created by Narek Aghekyan on 4/5/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef Brackets_h
#define Brackets_h

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


unordered_map<char, char> bracketPairs{
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}
    
};

bool isOpeningBracket(const char symbol)
{
    return bracketPairs.find(symbol) != bracketPairs.end();
}

bool isClosingBracket(const char symbol)
{
    for (auto& pair : bracketPairs)
    {
        if (symbol == pair.second)
        {
            return true;
        }
    }
    
    return false;
}

bool isMatchingBracketExist(const stack<char>& openingBrackets, const char bracket)
{
    if (!openingBrackets.empty())
    {
        const char prevBracket = openingBrackets.top();
        if (bracketPairs[prevBracket] == bracket)
        {
            return true;
        }
    }
    
    return false;
}

int solution(string &S)
{
    stack<char> openingBrackets;
    
    for (auto elem : S)
    {
        if (isOpeningBracket(elem))
        {
            openingBrackets.push(elem);
        }
        else if (isClosingBracket(elem))
        {
            if (isMatchingBracketExist(openingBrackets, elem))
            {
                openingBrackets.pop();
            }
            else
            {
                return 0;
            }
        }
    }
    
    const bool isAllOpeningBracketsMatched = openingBrackets.size() == 0;
    return isAllOpeningBracketsMatched ? 1 : 0;
}

#endif /* Brackets_h */
