#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *result = (int*)malloc(numsSize * sizeof(int));
    int totalProduct = 1;
    int zeroCount = 0;
    
    // Calculate the total product of all non-zero elements
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            totalProduct *= nums[i];
        } else {
            zeroCount++;
        }
    }

    // If there are more than one zero, all products will be zero
    if (zeroCount > 1) {
        for (int i = 0; i < numsSize; i++) {
            result[i] = 0;
        }
    } else {
        for (int i = 0; i < numsSize; i++) {
            if (zeroCount == 1) {
                // If there is one zero, only the position of the zero should be non-zero in result
                if (nums[i] == 0) {
                    result[i] = totalProduct;
                } else {
                    result[i] = 0;
                }
            } else {
                // If there are no zeros, calculate the result by dividing the total product by nums[i]
                result[i] = totalProduct / nums[i];
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
