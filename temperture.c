/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize){
    double *rtn = (double *)malloc(sizeof(double) * 2);
    rtn[0] = celsius + 273.15;
    rtn[1] = celsius * 1.80 + 32.00;
    *returnSize = 2;
    return rtn;
}
