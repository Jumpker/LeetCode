#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b,c) ((c<((a<b)?a:b))?c:((a<b)?a:b))
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    /*
    1. 定义每轮决策，定义状态
    每轮状态为这一格可以和自己左上方的格子形成边长为多少的正方形
    依次从左到右，从上到下遍历格子

    2. 列出状态转移方程
    只用看自己左边、上方、左上方的数的最小值就好了，然后当前状态最小值dp[i][j]=min(上、左、左上) + 1

    3. 约束状态和初始条件
    从dp[1][1]开始dp
    */

    int m = matrixSize, n = matrixColSize[0];
    int result = 0;
    int dp[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) dp[i][j]=((matrix[i][j]=='1')?1:0);              //初始化dp数组，睁大眼睛看好，原数组为char类型
    }

    for(int j=0; j<n; j++){
        if(dp[0][j]){
            result = 1;
            break;
        }
    }
    if(!result){
        for(int i=0; i<m; i++){
            if(dp[i][0]){
                result = 1;
                break;
            }
        }
    }
    //以上遍历第一行和第一列，给result赋初值
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(dp[i][j]){                                           //该格!=0才往下，否则直接下一个
                dp[i][j] = MIN(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1;         //状态转移方程
            }
            result = MAX(dp[i][j],result);                          //result取当前result和当前状态的更大值
        }
    }
    return result*result;                                               //返回边长的平方，即面积
}