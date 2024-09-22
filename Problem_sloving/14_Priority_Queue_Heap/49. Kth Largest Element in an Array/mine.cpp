// QUICK SELECT?
// a vector and an order 
// select a pivot then chack move larger elements to the right and lower to the left
// do this operation at max k times on the right side if the lenght - index is less tha 3 and 
// on the left if the lenght - index is greater than 3
// this could be considered as a searching algorithm with ACS O(n) and O(n^2) in the WCS
// we have a small problem, what if we have more than one element with the same value?
// if we have a size = k then its the minimum element in the portion [neglect this]
// if we have a size = k-1 then its the pivot
// if we have a size < k-1 then take the lower portion
// if we have a size > k-1 then.. two cases 
// first: no redundancy
// second: with redundancy ( ex: [4, 4, 4, 3, 3, 4] with k=5 or [4, 4, 4, 4] with k=2)
// [2, 9, 9, 9, 10, 2, 2, 1, 4, 3],  k = 2
/*
 2: [9, 9, 9, 2, 2, 4, 3]
 9: [9, 9, 9, 10] 
 9: [9, 9, 9, 10] 
 9: [9, 9, 9, 10] 
 0: skip not greater than 9
 2: skip
 2: skip
 1: skip
 4: skip not in range from 9 to 9
 3: skip not in range from 9 to 9
*/
// NOTE: the limits are sitten based on size of the new portion

#include <vector>

using namespace std;

class Solution {
public:

    // Always select the first element as a pivot 
    int getPivotOrder(vector<int>& nums, int pivot){
        int order = 0;

        for(int num : nums){
            if (num >= pivot)
                order++;
        }
        return order;
    }

    int findKthLargest(vector<int>& nums, int k) {
        
        for(int num : nums){
            
        }
    }
};