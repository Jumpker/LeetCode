#define MIN(a,b) ((a<b)?a:b)

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    if(gridSize==0) return 0;

    /*
    动态规划
    1. 确定决策定义状态，定义dp
    每轮决策为向下或向右移动一步，每轮状态为到该格子的数字最小值，即dp[i][j]为到该格子的数字最小值

    2. 找出最优子结构，得到状态转移方程
    dp[i][j] = MIN(dp[i-1][j](从左边转移来的),dp[i][j-1](从上边转移来)) + grid[i][j]

    3. 确定边界条件
    dp[0][0] = grid[0][0];
    首行/首列只能从左边/上边转移来

    顺便就把grid当dp吧
    */

    int m=gridSize, n=gridColSize[0];

    for(int i=1; i<m; i++){                                     //首行的状态转移方程
        grid[i][0] = grid[i-1][0] + grid[i][0];
    }

    for(int j=1; j<n; j++){                                     //首列的状态转移方程
        grid[0][j] = grid[0][j-1] + grid[0][j];
    }

    for(int i=1; i<m; i++){                                     //其他格子的状态转移方程
        for(int j=1; j<n; j++){
            grid[i][j] = MIN(grid[i-1][j],grid[i][j-1]) + grid[i][j];
        }
    }

    return grid[m-1][n-1];
}