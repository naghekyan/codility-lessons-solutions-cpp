//
//  CyclicRotation.h
//  Test
//
//  Created by Narek Aghekyan on 3/28/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef CyclicRotation_h
#define CyclicRotation_h

int getIndex(int currentIndex, int shiftSize, int arraySize)
{
    return (currentIndex + shiftSize) % arraySize;
}

vector<int> solution(vector<int> &A, int K) {
    
    auto copyVec = A;
    const int arraySize = static_cast<int>(copyVec.size());
    for (int i = 0; i < arraySize; ++i)
    {
        const auto newIndex = getIndex(i, K, arraySize);
        swap(A[i], copyVec[newIndex]);
    }
    
    return copyVec;
}


#endif /* CyclicRotation_h */
