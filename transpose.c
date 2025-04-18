/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int m=matrixSize, n=matrixColSize[0];
    int** res = malloc(sizeof(int *) * n);
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    for(int i=0; i<n; i++){
        res[i] = malloc(sizeof(int) * m);
        (*returnColumnSizes)[i] = m;
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            res[j][i] = matrix[i][j];
        }
    }
    return res;
}