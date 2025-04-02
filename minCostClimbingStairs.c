#define MIN(a,b) ((a<b)?a:b)
int minCostClimbingStairs(int* cost, int costSize) {
    int next=0, a=0, b=0;
    for(int i=2; i<=costSize; i++){
        next = MIN(b + cost[i-1],a + cost[i-2]);
        a=b;
        b=next;
    }
    return b;
}