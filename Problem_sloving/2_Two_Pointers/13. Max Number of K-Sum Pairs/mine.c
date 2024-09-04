#include <stdio.h>
#include <stdlib.h>

/*Hash Map Approach: Time complexity is O(n), where n is the number of elements in the array. 
Space complexity is also O(n) due to the hash map.

NOTE: we used array map insted of hash map which is less space efficient
*/

// Function to return the minimum of two integers
int min(int a, int b){
    return (a > b) ? b : a;
}

// Function to calculate the maximum number of operations to achieve pairs that sum up to k
int maxOperations(int* nums, int numsSize, int k){
    
    // Allocate memory for counters to keep track of occurrences of numbers less than k
    // calloc is a memory allocation function in C that stands for "contiguous allocation." 
    // It's used to allocate memory for an array of elements and automatically initializes 
    // all the allocated memory to zero
    
    int* counters = (int*)calloc((k-1), sizeof(int));
    int result = 0;

    // Count occurrences of each number in the nums array that is less than k
    for(int i = 0; i < numsSize; i++){
        if(nums[i] < k){
            counters[nums[i]-1]++;
        }
    }
    // printf("result: %d\n", result);

    // Calculate the maximum number of valid pairs
    for(int i = 0; i < (k / 2 - 1); i++){
        result += min(counters[i], counters[k - i - 2]);
        // printf("result: %d\n", result);

    }

    // for(int i = 0; i < k-1; i++){
    //     printf("%d ", counters[i]);
    // }
    // printf("\nresult: %d\n", result);

    // If k is even, handle the middle element
    if(k % 2 == 0){
        result += (counters[k / 2 - 1]) / 2;
    }

    // If k is odd, handle the middle element pair
    else if(k != 1){
        result += min(counters[k / 2 - 1], counters[k / 2]);
    }

    return result;
}

int main() {
    // Sample input array and its size
    int nums[] = {3,2,3,2,3,2,3,2,3,2,3};
;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 5; // Target sum

    // Calculate the maximum number of operations and print the result
    int result = maxOperations(nums, numsSize, k);
    printf("The maximum number of operations is: %d\n", result);

    return 0;
}
