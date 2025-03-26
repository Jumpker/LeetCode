int searchInsert(int* nums, int numsSize, int target) {
    int left=0, right=numsSize-1, ans=numsSize;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]>=target){
            right = mid-1;
            ans = mid;
        }
        else left = mid+1;
    }
    return ans;
}