int rob(int* nums, int numsSize) {
    if(numsSize == 1)
        return nums[0];
    int total_nums = 0; 
    int nums_sum[numsSize];
    memset(nums_sum,0,numsSize);
    nums_sum[0] = nums[0];
    nums_sum[1] = nums[1];
    if(numsSize == 2)
        goto ret;
    
    nums_sum[2] = nums[2] + nums[0];
    for(int i=3;i<numsSize;i++){
        total_nums = nums_sum[i-3] > nums_sum[i-2] ? nums_sum[i-3] : nums_sum[i-2];;
        nums_sum[i] = total_nums + nums[i];
    }
ret:
    total_nums = nums_sum[numsSize-1] > nums_sum[numsSize-2] ? nums_sum[numsSize-1] : nums_sum[numsSize-2];
    return total_nums;
}