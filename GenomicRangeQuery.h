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
    static unordered_map<char, int> impactFactor{{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
    return impactFactor[a];
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
    const int strSize = static_cast<int>(S.size());
    unordered_map<char, int> counters;
    
    const vector<int> forInitialization(strSize, 0);
    map<char, vector<int>> countOfNucleotideTillIndex{
        {'A', forInitialization},
        {'C', forInitialization},
        {'G', forInitialization},
        {'T', forInitialization}
    };
    
    
    for (int i = 0; i < strSize; ++i)
    {
        const char elem = S[i];
        ++counters[elem];
        
        for (auto& elem : countOfNucleotideTillIndex)
        {
            const char nucleotide = elem.first;
            auto& countTillIndex = elem.second;
            countTillIndex[i] = counters[nucleotide];
        }
    }
    
    const int rangeCount = static_cast<int>(P.size());
    vector<int> results(rangeCount, 0);
    
    for (int i = 0; i < rangeCount; ++i)
    {
        const int rangeStart = P[i];
        const int rangeEnd = Q[i];
        
        if (rangeEnd - rangeStart == 0)
        {
            results[i] = getImpactFactor(S[rangeStart]);
        }
        else
        {
            for (auto& elem : countOfNucleotideTillIndex)
            {
                const char nucleotide = elem.first;
                auto& countTillIndex = elem.second;
                
                if (countTillIndex[rangeEnd] - countTillIndex[rangeStart] > 0 || S[rangeStart] == nucleotide)
                {
                    results[i] = getImpactFactor(nucleotide);
                    break;
                }
            }
        }
    }
    
    return results;
}

#endif /* GenomicRangeQuery_h */
