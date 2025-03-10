/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int l=0, r=n;
    *returnSize = 2*n;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    for(l; l<n; l++,r++){
        result[2*l] = nums[l];
        result[2*l+1] = nums[r];
    }
    return result;
}