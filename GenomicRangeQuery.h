//
//  GenomicRangeQuery.h
//  Test
//
//  Created by Narek Aghekyan on 3/30/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef GenomicRangeQuery_h
#define GenomicRangeQuery_h

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
using namespace std;

int getImpactFactor(char a)
{
    switch (a)
    {
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
    }
    
    return -1; // OK, compiler, I will return a value here too, just shut up!
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
    const int strSize = static_cast<int>(S.size());
    
    int counterA = 0;
    int counterC = 0;
    int counterG = 0;
    int counterT = 0;
    
    vector<int> countOfATillIndex(strSize, 0);
    vector<int> countOfCTillIndex(strSize, 0);
    vector<int> countOfGTillIndex(strSize, 0);
    vector<int> countOfTTillIndex(strSize, 0);
    
    for (int i = 0; i < strSize; ++i)
    {
        const char elem = S[i];
        
        switch (elem)
        {
            case 'A':
                ++counterA;
                break;
            case 'C':
                ++counterC;
                break;
            case 'G':
                ++counterG;
                break;
            case 'T':
                ++counterT;
                break;
        }
        
        countOfATillIndex[i] = counterA;
        countOfCTillIndex[i] = counterC;
        countOfGTillIndex[i] = counterG;
        countOfTTillIndex[i] = counterT;
    }
    
    
    const int rangeCount = static_cast<int>(P.size());
    vector<int> results(rangeCount, 0);
    
    for (int i = 0; i < rangeCount; ++i)
    {
        const int rangeStart = P[i];
        const int rangeEnd = Q[i];
        
        if (rangeEnd - rangeStart == 0)
        {
            results[i] =getImpactFactor(S[rangeStart]);
        }
        else if (countOfATillIndex[rangeEnd] - countOfATillIndex[rangeStart] > 0 || S[rangeStart] == 'A')
        {
            results[i] = getImpactFactor('A');
        }
        else if (countOfCTillIndex[rangeEnd] - countOfCTillIndex[rangeStart] > 0 || S[rangeStart] == 'C')
        {
            results[i] = getImpactFactor('C');
        }
        else if (countOfGTillIndex[rangeEnd] - countOfGTillIndex[rangeStart] > 0 || S[rangeStart] == 'G')
        {
            results[i] = getImpactFactor('G');
        }
        else if (countOfTTillIndex[rangeEnd] - countOfTTillIndex[rangeStart] > 0 || S[rangeStart] == 'T')
        {
            results[i] = getImpactFactor('T');
        }
    }
    
    return results;
}


#endif /* GenomicRangeQuery_h */
