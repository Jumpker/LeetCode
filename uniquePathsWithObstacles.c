int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m=obstacleGridSize, n=obstacleGridColSize[0];
    if(obstacleGrid[0][0]==1) return 0;
    if(m==1 && n==1) return 1;

    int flag=1;
    for(int i=1; i<m; i++){                   //首行状态转移方程
        if(obstacleGrid[i][0]==1) flag = 0;
        obstacleGrid[i][0] = flag;
    }

    flag = 1;
    for(int j=1; j<n; j++){                   //首列状态转移方程
        if(obstacleGrid[0][j]==1) flag = 0;
        obstacleGrid[0][j] = flag;
    }

    for(int i=1; i<m; i++){                    //其他状态转移方程
        for(int j=1; j<n; j++){
            if(obstacleGrid[i][j] == 1){
                obstacleGrid[i][j] = 0;
                continue;
            }
            obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
        }
    }

    return obstacleGrid[m-1][n-1];
}