#define MIN(a,b) ((a<b)?a:b)
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int m=triangleSize;
    /*
    1. 确定每轮决策，定义状态
    每轮决策为移动到下面的哪个位置上，也就是移动到下行的j还是j+1的位置上。
    状态dp[i][j]为移动到该位置的最小路径和

    2. 确定状态转移方程
    dp[i][j] = MIN(dp[i-1][j-1],dp[i-1][j])

    3. 边界条件
    dp[i][0]只能由dp[i-1][0]转移过来
    dp[i][n-1]只能由dp[i-1][n]转移过来
    */

    for(int i=1; i<m; i++){
        triangle[i][0] += triangle[i-1][0];
        triangle[i][triangleColSize[i]-1] += triangle[i-1][triangleColSize[i-1]-1];
    }
    for(int i=2; i<m; i++){
        for(int j=1; j<triangleColSize[i]-1; j++){
            triangle[i][j] = MIN(triangle[i-1][j-1],triangle[i-1][j]) + triangle[i][j];
        }
    }

    int min = triangle[m - 1][0];
    for(int i=0; i<triangleColSize[m-1]; i++){
        min = MIN(min,triangle[m-1][i]);
    }
    return min;
}