/*Left and Right Pointers: The right pointer is used to expand the window by iterating over the array. 
    The left pointer is used to shrink the window when the number of zeros in the window exceeds k.
Zero Count: zero_count keeps track of how many zeros are currently in the window.
Max Length: max_len keeps track of the maximum length of the window that contains at most k zeros.*/

#include <stdio.h>

int longestOnes(int* nums, int numsSize, int k) {
    int left = 0, right;
    int max_len = 0;
    int zero_count = 0;

    for (right = 0; right < numsSize; right++) {
        if (nums[right] == 0) {
            zero_count++;
        }

        // If there are more than 'k' zeros, shrink the window from the left
        while (zero_count > k) {
            if (nums[left] == 0) {
                zero_count--;
            }
            left++;
        }

        // Calculate the length of the current valid window
        max_len = (right - left + 1) > max_len ? (right - left + 1) : max_len;
    }

    return max_len;
}

int main() {
    // Test case 1
    int nums1[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    int result1 = longestOnes(nums1, sizeof(nums1)/sizeof(nums1[0]), k1);
    printf("Test Case 1: %d\n", result1); // Expected output: 6

    // Test case 2
    int nums2[] = {0, 0, 1, 1, 1, 0, 0};
    int k2 = 0;
    int result2 = longestOnes(nums2, sizeof(nums2)/sizeof(nums2[0]), k2);
    printf("Test Case 2: %d\n", result2); // Expected output: 3

    // Test case 3
    int nums3[] = {0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0};
    int k3 = 3;
    int result3 = longestOnes(nums3, sizeof(nums3)/sizeof(nums3[0]), k3);
    printf("Test Case 3: %d\n", result3); // Expected output: 9

    // Test case 4
    int nums4[] = {1, 0, 1, 1, 0, 1, 0, 0, 1, 1};
    int k4 = 2;
    int result4 = longestOnes(nums4, sizeof(nums4)/sizeof(nums4[0]), k4);
    printf("Test Case 4: %d\n", result4); // Expected output: 7

    // Test case 5
    int nums5[] = {1, 1, 1, 1};
    int k5 = 2;
    int result5 = longestOnes(nums5, sizeof(nums5)/sizeof(nums5[0]), k5);
    printf("Test Case 5: %d\n", result5); // Expected output: 4

    return 0;
}
