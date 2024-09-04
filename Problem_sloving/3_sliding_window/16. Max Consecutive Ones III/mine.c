#include <stdio.h>

int longestOnes(int* nums, int numsSize, int k);

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


int longestOnes(int* nums, int numsSize, int k) {
    int i=0, ones=0, longest=0, lives=k, checkpoint=0;

    while( (i<numsSize)  ){ //&& (k>=0)
        if(nums[i] == 1){ // update ones

            ones++;
            if (ones>=longest){
                longest = ones;
            }
        }
        else if(nums[i] == 0){
            if(lives>0){ // flip and update ones

                lives--;
                if (lives == k-1){
                    checkpoint = i;
                }

                ones++;
                if (ones>=longest){
                    longest = ones;
                }
            }
            else{ // reset counters ;
                ones = 0;
                lives = k;
                if(k > 0){
                    i = checkpoint; // you can use shrinking window instead of checkpoints (check another.c)
                }
            }
        }
        
        i++;
    }

    return longest;
}
