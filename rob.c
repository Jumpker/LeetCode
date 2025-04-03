#define MAX(a,b) ((a>b)?a:b)
int rob(int* nums, int numsSize) {
    
    if(numsSize==0) return 0;
    if(numsSize==1) return nums[0];
    if(numsSize==2) return MAX(nums[0],nums[1]);
    if(numsSize==3) return MAX(nums[0]+nums[2],nums[1]);
    if(numsSize==4) return MAX(nums[0]+nums[3],MAX(nums[0]+nums[2],nums[1]+nums[3]));

    int a=nums[0], b=nums[1], c=nums[2]+nums[0], d, money=0;
    for(int i=3; i<numsSize; i++){
        d = MAX(a+nums[i],b+nums[i]);
        money = MAX(money,d);
        a = b;
        b = c;
        c = d;
    }
    return money;
}