//
//  BinaryGap.hpp
//  Test
//
//  Created by Narek Aghekyan on 3/28/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef BinaryGap_hpp
#define BinaryGap_hpp

#include <iostream>
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

std::string getBits(int n)
{
    std::string result(33, '0');
    
    int oneBit = 1;
    for (int i = 0; i < 33; ++i)
    {
        result[i] = (n & oneBit) ? '1' : '0';
        oneBit = oneBit << 1;
    }
    
    //std::reverse(result.begin(), result.end());
    return result;
}

int solution(int N) {
    std::string bitsStr = getBits(N);
    std::cout << bitsStr << std::endl;
    
    int result = 0;
    
    bool isFirstBitSetToOne = true;
    int i = 0;
    
    for (int j = 0; j < bitsStr.size(); ++j)
    {
        if(bitsStr[j] == '1')
        {
            if (!isFirstBitSetToOne)
            {
                result = std::max(j-i-1, result);
            }
            i = j;
            isFirstBitSetToOne = false;
        }
    }
    
    return result;
}

#endif /* BinaryGap_hpp */
