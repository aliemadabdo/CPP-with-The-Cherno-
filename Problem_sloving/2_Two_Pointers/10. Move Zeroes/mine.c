void moveZeroes(int* nums, int numsSize) {
    int noneZero = 0;

    for (int i=0; i<numsSize; i++){
        if(nums[i] != 0){
            nums[noneZero] = nums[i];
            noneZero++;
        }
    }

    for(int i = noneZero; i<numsSize; i++){
        nums[i] = 0;
    }
}