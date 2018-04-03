//
//  MinAvgTwoSlice.h
//  Test
//
//  Created by Narek Aghekyan on 4/3/18.
//  Copyright © 2018 Narek Aghekyan. All rights reserved.
//

#ifndef MinAvgTwoSlice_h
#define MinAvgTwoSlice_h

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
using namespace std;


int solution(vector<int> &A)
{
    /*
     Every slice which has a size larger than 3 elements can be divided to 2 and 3 element slices. Even sized slices can be divided to several 2-sized sub-slices and odd-sized slices can be divided to one 3-sized and several 2-sized ones. Such large slices (size > 3) in case they have global minimum of the average (GMA) for all the possible sub-slices of the array, then we can proof that one of the sub-slices (2 or 3 sized) of that large sub-slice also has the same average and actually all subslices have the same average. Let's consider that this assumtion is not true. In that case some of the subslices have different averages compared to GMA and let's denote one of them with AVG.
     1) In case AVG < GMA, this is in contradiction with our initial assumtion that the large slice (let's name it S) had the global minimum of the average.
     2) In case AVG > GMA, then in the large slice S there is another sub-slice whose average (let's denote with AVG_2) satisfies to AVG_2 < GMA, which again contradicts to our initial assumption that GMA is the minimum average. Let see why when AVG > GMA => AVG_2 < GMA.
     
     Let say S slice has N elements and GMA = (a1 + a2 + ... + aN) / N; And AVG = (a1 + ... + aM) / M; AVG_2 = (a(M+1) + ... + aN) / (N - M); Lets substitute these expressions to the initial expression of GMA:
     GMA = (M * AVG + (N - M) * AVG_2) / N i.e. GMA * N = M * AVG + (N - M) * AVG_2. Now it should be obvious that when AVG > GMA then should satisfy to AVG_2 > GMA in order to bring back to the equality.
     
     This leaves us with only one posibility, GMA = AVG = AVG_2 for all the subslices, again, if the initial large slice average was the global minimum. Therefore, we could just consider 2 and 3 sized slices to solve the problem.
     
     P.S. This solution ia based on this blogpost and you can see the details there: https://codesays.com/2014/solution-to-min-avg-two-slice-by-codility/#comment-11281
     */
    
    const int size = static_cast<int>(A.size());
    double minSliceAvg = std::numeric_limits<double>::max();
    int minIndex = 0;
    
    for (int i = 0; i < size - 2; ++i)
    {
        const double twoElemAvg = (A[i] + A[i + 1]) / 2.0;
        const double threeElemAvg = (A[i] + A[i + 1] + A[i + 2]) / 3.0;
        const double minOfTwo = min(twoElemAvg, threeElemAvg);
        
        if (minOfTwo < minSliceAvg)
        {
            minIndex = i;
            minSliceAvg = minOfTwo;
        }
    }
    
    const double unconsideredTwoElemSliceAvg = (A[size - 2] + A[size - 1]) / 2;
    
    if (unconsideredTwoElemSliceAvg < minSliceAvg)
    {
        minIndex = size - 2;
        minSliceAvg = unconsideredTwoElemSliceAvg;
    }
    
    return minIndex;
}


#endif /* MinAvgTwoSlice_h */
