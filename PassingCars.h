//
//  PassingCars.h
//  Test
//
//  Created by Narek Aghekyan on 3/30/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef PassingCars_h
#define PassingCars_h

int solution(vector<int> &A)
{
    int countOfOnes = 0;
    int pairCount = 0;
    
    for (int i = static_cast<int>(A.size()) - 1; i >= 0; --i)
    {
        const int elem = A[i];
        
        if (elem == 1)
        {
            ++countOfOnes;
        }
        else
        {
            pairCount += countOfOnes;
            
            if (pairCount > 1e9)
            {
                return -1;
            }
        }
    }
    
    return pairCount;
}

#endif /* PassingCars_h */
