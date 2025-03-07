/**
以下是错误示范，正确应该把if那块改为正经的abs()绝对值
*/
#include <stdio.h>
int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int cnt=0;
    for(int i=0; i<=arrSize-3; i++){
        for(int j=i+1; j<=arrSize-2; j++){
            for(int k=j+1; k<=arrSize-1; k++){
                if(
                (arr[i]-arr[j] <= a || arr[i]-arr[j] >= -a) &&
                (arr[j]-arr[k] <= b || arr[j]-arr[k] >= -b) &&
                (arr[i]-arr[k] <= c || arr[i]-arr[k] >= -c)
                ) cnt++;
            }
        }
    }
    return cnt;
}

void main(){
    int arr[]={3,0,1,1,9,7};
    int a=7, b=2, c=3;
    int arrSize=sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", countGoodTriplets(arr, arrSize, a, b, c));
}
