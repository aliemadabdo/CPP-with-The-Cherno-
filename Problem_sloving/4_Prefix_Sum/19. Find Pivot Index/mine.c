#include <stdio.h>

int pivotIndex(int* nums, int numsSize) {
    int leftSum[numsSize] , rightSum[numsSize];

    rightSum[numsSize-1] = 0;
    leftSum[0] = 0; 

    for(int i=numsSize-2; i>=0; i--){
        rightSum[i] = rightSum[i+1] + nums[i+1];
    }

    for(int i=0; i<numsSize-1; i++){
        leftSum[i+1] = leftSum[i] + nums[i];

        // printf("\nright sum for %d = %d", nums[i], rightSum[i]);
        // printf("\nleft sum for %d = %d", nums[i], leftSum[i]);

        if(rightSum[i]==leftSum[i]){
            return i;
        }
    }
    
    if(rightSum[numsSize-1]==leftSum[numsSize-1]){
        return numsSize-1;
    }
    else{
        return -1;
    }

}

int main() {
    int nums[] = {2,1,-1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int pivot = pivotIndex(nums, numsSize);
    if (pivot != -1) {
        printf("\nPivot index is: %d\n", pivot);
    } else {
        printf("\nNo pivot index found.\n");
    }

    return 0;
}