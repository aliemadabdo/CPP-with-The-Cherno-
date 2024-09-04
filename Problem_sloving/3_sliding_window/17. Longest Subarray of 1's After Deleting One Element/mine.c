
/* Special case of problem 16 with k = 1 and subtracting 1 from the result. */

#include <stdio.h>

int longestSubarray(int* nums, int numsSize) {
    int left = 0, right = 0;
    int zero_count = 0;
    int longest = 0;

    while (right < numsSize) {
        if (nums[right] == 0) {
            zero_count++;
        }

        while (zero_count > 1) {
            if (nums[left] == 0) {
                zero_count--;
            }
            left++;
        }

        longest = (right - left + 1) > longest ? (right - left + 1) : longest;
        right++;
    }

    // Subtract one because we need to delete one `0`.
    return longest - 1;
}

int main() {
    // Test case 1
    int nums1[] = {0,1,1,1,0,1,1,0,1};
    int result1 = longestSubarray(nums1, sizeof(nums1)/sizeof(nums1[0]));
    printf("Test Case 1: %d\n", result1); // Expected output: 6

    // Test case 2
    int nums2[] = {1,1,0,1};
    int result2 = longestSubarray(nums2, sizeof(nums2)/sizeof(nums2[0]));
    printf("Test Case 2: %d\n", result2); // Expected output: 3

    // Test case 3
    int nums3[] = {0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0};
    int result3 = longestSubarray(nums3, sizeof(nums3)/sizeof(nums3[0]));
    printf("Test Case 3: %d\n", result3); // Expected output: 9

    // Test case 4
    int nums4[] = {1, 0, 1, 1, 0, 1, 0, 0, 1, 1};
    int result4 = longestSubarray(nums4, sizeof(nums4)/sizeof(nums4[0]));
    printf("Test Case 4: %d\n", result4); // Expected output: 7

    // Test case 5
    int nums5[] = {1, 1, 1, 1};
    int result5 = longestSubarray(nums5, sizeof(nums5)/sizeof(nums5[0]));
    printf("Test Case 5: %d\n", result5); // Expected output: 4

    return 0;
}
