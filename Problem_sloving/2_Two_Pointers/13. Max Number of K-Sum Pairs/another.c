#include <stdio.h>
#include <stdlib.h>
/*Two-Pointer Approach: Time complexity is 𝑂(𝑛log𝑛) due to the sorting step, 
and space complexity is 𝑂(1) as no extra space is used.*/

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maxOperations(int* arr, int size, int k) {
    // Sort the array
    qsort(arr, size, sizeof(int), compare);

    int left = 0;
    int right = size - 1;
    int count = 0;

    while (left < right) {
        int current_sum = arr[left] + arr[right];
        if (current_sum == k) {
            count++;
            left++;
            right--;
        } else if (current_sum < k) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}

int main() {
    int arr[] = {1, 5, 7, 1, 9, 5, 3, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 10;

    int result = maxOperations(arr, size, k);
    printf("Maximum number of pairs with sum %d is %d\n", k, result);

    return 0;
}
