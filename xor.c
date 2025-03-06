int xorOperation(int n, int start) {
    int nums[n];
    nums[0] = start;
    for(int i=1; i<n; i++){
        nums[i] = start + 2*i;
        nums[0] ^= nums[i];
    }
    return nums[0];
}