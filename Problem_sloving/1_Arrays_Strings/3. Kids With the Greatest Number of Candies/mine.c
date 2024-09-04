#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    uint8_t theGreatest = 0;
    bool* results = (bool*)malloc(candiesSize * sizeof(bool));

    /* Get the greatest number of candies with on kid. Complexity: O(n) */
    for (int i = 0; i < candiesSize; i++){
        if (candies[i] > theGreatest){
            theGreatest = candies[i];
        }
    }

    for (int i = 0; i < candiesSize; i++){
        results[i] = candies[i] + extraCandies >= theGreatest; // Trick
    }

    *returnSize = candiesSize;

    return results; 
}


// Function to print an array of bool
void printBoolArray(bool* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i] ? "true" : "false");
    }
    printf("\n");
}

int main() {
    // Test case
    int candies[] = {};
    int extraCandies = 3;
    int candiesSize = sizeof(candies) / sizeof(candies[0]);
    int returnSize;

    // Call the kidsWithCandies function
    bool* result = kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);

    // Print the results
    if (result != NULL) {
        printf("Results:\n");
        printBoolArray(result, returnSize);

        // Free the allocated memory
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}