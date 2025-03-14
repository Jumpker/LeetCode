int removeDuplicates(int* nums, int numsSize) {
    int num, k=1, front=nums[0], insert=0;
    bool flag = true;
    for(int i=1; i<numsSize; i++){
        if(flag && nums[i] == nums[i-1]){
            insert = i;
            flag = false;
        }
        else if(nums[i] != nums[i-1]){
            k++;
            if(insert){
                nums[insert] = nums[i];
                insert++;
            }
        }
    }
    return k;
}