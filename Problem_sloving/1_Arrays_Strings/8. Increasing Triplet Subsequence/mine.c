#include <stdbool.h>

// @attention: complexity O(n^2) leads to TLM error

bool increasingTriplet(int* nums, int numsSize) {
    int small = 0, large = 0;
    if(numsSize < 3){
        return false; // early return
    }
    
    // we can compare each element with all before and after it.(time complexity = O(n^2) & space complexity = (1))
    for (int i=1; i<numsSize-1; i++){
        for(int j=0; j<i; j++){
            if (nums[j] < nums[i]){
                small = 1;
                break;
            }
        }

        for(int j=i+1; j<numsSize; j++){
            if (nums[j] > nums[i]){
                large = 1;
                break;
            }
        }

        if(small && large){
            return true;
        }
        else{
            small = 0; 
            large = 0;
        }
    }


    return false;

    // we can sort first to reach the required solution. (not a complete solution)
    // nums = bubbleSort(nums, numsSize); // (time complexity > O(n) & space complexity = o(1))

    // for (int i=1; i<numsSize-1; i++){
    //     if(nums[i-1] < nums[i])
    //         if (nums[i] < nums[i+1]){
    //             return true; //early return
    //         }
    //         else{
    //             i++; // skip the next triple
    //         }
    // }

}


// int* bubbleSort(int arr[], int size){
//     int temp;
    
//     for(int i=size-1; i>0; i--){
//         for(int j=0; j<i; j++){
//             if(arr[j] > arr[j+1]){
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }

//     return arr;
// }