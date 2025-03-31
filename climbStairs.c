int climbStairs(int n) {
    int p=1, q=2;
    if(n==1) return p;
    if(n==2) return q;                  //爬一二级时有1、2种可能
    int r;
                                        //第三级开始的方法数 = n-1级的方法数+n-2级的方法数
    for(int i=3; i<=n; i++){
        r = p + q;                      //第n级的方法数
        p = q;                          //让原是n-2方法数的p=n-1的方法数(为下次循环准备)
        q = r;                          //让原是n-1方法数的q=n的方法数(为下次循环准备)
    }
    return r;
}