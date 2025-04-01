int fib(int n) {
    int p=0, q=1;
    if(n==0) return p;
    if(n==1) return q;
    int r;
    for(int i=2; i<=n; i++){
        r = p + q;
        p = q;
        q = r;
    }
    return r;
}