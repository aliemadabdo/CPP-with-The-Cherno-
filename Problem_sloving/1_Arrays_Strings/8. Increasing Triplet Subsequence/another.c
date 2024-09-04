
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/* LOGICAL TRICK */ 

bool increasingTriplet(int* nums, int numsSize) {
    int first = INT_MAX, second = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= first) {
            first = nums[i]; // update first if nums[i] is smaller than or equal to first
        } else if (nums[i] <= second) {
            second = nums[i]; // update second if nums[i] is smaller than or equal to second
        } else {
            // if we find a number greater than both first and second, we have found our triplet
            return true;
        }
    }
    
    return false; // no such triplet found
}

int main() {
    int nums[] = {20, 100, 10, 12, 5, 13};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    if (increasingTriplet(nums, numsSize)) {
        printf("There exists an increasing triplet subsequence.\n");
    } else {
        printf("There does not exist an increasing triplet subsequence.\n");
    }

    return 0;
}
