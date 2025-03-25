int removeElement(int* nums, int numsSize, int val) {
    int k=0, front=0;
    if(!numsSize) return 0;
    if(numsSize==1 && nums[0]!=val) return 1;
    if(nums[numsSize-1]!=val) k++;
    for(int i=1; i<numsSize; i++){
        if(nums[front]!=val){
            front++;
            k++;
        }
        if(nums[front]==val){                                      //查找到等于val的元素
            nums[front]=nums[i];
            nums[i]=val;
        }
    }
    return k;
}