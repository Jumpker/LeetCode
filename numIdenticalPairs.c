int numIdenticalPairs(int* nums, int numsSize) {
    int num = 0;
    for(int i=0; i<numsSize-1; i++){
        for(int j=i+1; j<numsSize; j++){
            if(nums[i] == nums[j]) num++;
        }
    }
    return num;
}

int numIdenticalPairs_Hash(int* nums, int numsSize) {
    int ans = 0;
    int cnt[101] = {};
    for (int i = 0; i < numsSize; i++) {
        ans += cnt[nums[i]]++;              //先录入答案再更新哈希表cnt[]
    }
    return ans;
}