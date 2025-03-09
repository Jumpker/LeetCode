bool isPowerOfTwo(int n) {
    int cnt=0;
    if(n==0) return false;
    else if(n==-1) return false;
    else if(n<0) return isPowerOfTwo(-(1/n));
    else{
        while(n != 0){
            cnt += n%2;
            n = n >> 1;
            if(cnt > 1) return false;
        }
    return true;
    }
}

bool isPowerOfTwo_w(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}