#define MIN_3(a,b,c) ((c<((a<b)?a:b))?c:((a<b)?a:b))
#define MIN_2(a,b) ((a<b)?a:b)

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    /*
    1. 确定每轮决策，定义状态
    每轮决策为往左下还是下还是右下走 (即(row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) )
    每轮状态为走到该格子的最小下降路径和 (dp[i][j])

    2. 列出状态转移方程
    dp[i][j] = MIN(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]) + dp[i][j]

    3. 定义约束和边界条件
        初始条件为第一行的dp值
    */

    int n = matrixSize;
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            if(!j) matrix[i][j] = MIN_2(matrix[i-1][j],matrix[i-1][j+1]) + matrix[i][j];        //遍历到第一列时
            else if(j==n-1) matrix[i][j] = MIN_2(matrix[i-1][j-1],matrix[i-1][j]) + matrix[i][j];        //遍历到第n列时
            else matrix[i][j] = MIN_3(matrix[i-1][j-1],matrix[i-1][j],matrix[i-1][j+1]) + matrix[i][j];        //遍历到中间列时
        }
    }

    int result = matrix[n-1][0];
    for(int i=1; i<n; i++){
        result = MIN_2(result,matrix[n-1][i]);
    }
    return result;
}