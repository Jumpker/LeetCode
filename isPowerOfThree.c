bool isPowerOfThree(int n) {
    if(n<=0) return false;
    while(n%3 == 0)
        n /= 3;
        if(n == 1) return true;
    return false;
}

bool isPowerOfThree_2(int n) {
    while(n && n%3==0)
        n /= 3;
    return n == 1;
}