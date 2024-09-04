#include <stdio.h>
#include <stdlib.h>

// @attention: optimized solution with complexity O(n).

/* MATHIMATICAL TRICK */ 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *result = (int*)malloc(numsSize * sizeof(int));
    int *leftProducts = (int*)malloc(numsSize * sizeof(int));
    int *rightProducts = (int*)malloc(numsSize * sizeof(int));
    
    // Initialize left and right product arrays
    leftProducts[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        leftProducts[i] = leftProducts[i - 1] * nums[i - 1];
    }
    
    rightProducts[numsSize - 1] = 1;
    for (int i = numsSize - 2; i >= 0; i--) {
        rightProducts[i] = rightProducts[i + 1] * nums[i + 1];
    }
    
    // Calculate result array
    for (int i = 0; i < numsSize; i++) {
        result[i] = leftProducts[i] * rightProducts[i];
    }
    
    // Free temporary arrays
    free(leftProducts);
    free(rightProducts);
    
    return result;
}
// [1 1 2 6]
// [24 12 4 1]
int main() {
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = productExceptSelf(nums, numsSize, &returnSize);

    printf("Result array: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(result);

    return 0;
}
