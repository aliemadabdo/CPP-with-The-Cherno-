#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k);

int main() {
    // Example test case
    int nums[] = {1, 12, -5, -6, 4, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 4;

    double maxAverage = findMaxAverage(nums, numsSize, k);
    
    printf("Maximum average of subarray with length %d: %f\n", k, maxAverage);

    return 0;
}


double findMaxAverage(int* nums, int numsSize, int k) {
    int sum = 0;

    // initialize the window
    for(int i = 0; i<k; i++){
        sum += nums[i];
    }

    int maxSum = sum;

    // Slide the window across the array
    for(int i = k; i < numsSize; i++) {
        sum += nums[i] - nums[i - k];
        if(sum > maxSum) {
            maxSum = sum;
        }
    }

    return (double)maxSum/k;
}