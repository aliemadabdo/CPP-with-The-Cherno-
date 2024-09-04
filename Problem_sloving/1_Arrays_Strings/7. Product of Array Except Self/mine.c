#include <stdio.h>
#include <stdlib.h>

// @attention: complexity O(n^2) leads to TLM error

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *result = (int*)malloc(numsSize * sizeof(int));
    
    for(int i = 0; i < numsSize; i++){
        result[i] = 1;
        for (int j = 0; j < numsSize; j++) {
            if (i != j) {
                result[i] *= nums[j];
            }
        }
    }

    return result;
}

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
