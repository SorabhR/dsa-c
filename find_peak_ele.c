int binary_search(int* arr,int l,int h,int mid){
    int result = 0;
    if(mid == 0 && (arr[mid] > arr[mid+1]))
        return mid;
    if(mid != 0 && ((arr[mid] > arr[mid-1]) && (arr[mid] > arr[mid+1])))
        return mid;
    if((h-l >= 2)){
        result = binary_search(arr,l,mid,(l+(mid-l)/2));
        if(result != -1)
            return result;
        result = binary_search(arr,mid,h,(mid+(h-mid)/2));
        if(result != -1)
            return result;
    }
    return -1;
}


int findPeakElement(int* nums, int numsSize) {
    
    if(numsSize == 1)
        return 0;
    else if (nums[numsSize-1] > nums[numsSize-2]){
        return numsSize-1;
    }
    int mid = (numsSize-1)/2;
    return binary_search(nums,0,numsSize-1,mid);
}