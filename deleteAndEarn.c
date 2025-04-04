#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a>b)?a:b)

int deleteAndEarn(int* nums, int numsSize) {
    if(numsSize==0) return 0;
    if(numsSize==1) return nums[0];

    /*
    建立cnt[]，统计各个数字出现的次数。用cnt[nums[i]]++，注意要用calloc，因为要初始化为0
    建立point[]，统计每个数字总共能拿多少分。用point[i]=i*cnt[i]

    dp[]定义：          处理到数值i时能获得的最大点数（或者说，包含point[i]，已经积累的最大点数）
    状态转移方程为：    dp[i] = MAX(dp[i-1],dp[i-2]+point[i]);  在dp[i-1]和dp[i-2]+dp[i]中寻找更大值
    初始状态：          dp[0] = 0, dp[1] = point[1];

    用滚动数组优化dp数组：        a代替dp[i-2]; b代替dp[i-1]; earn代替dp[i]

    相当于优化成了打家劫舍模型
    */


    int max_num=0;                                      //寻找nums[]中的最大值，以构建cnt数组
    for(int i=0; i<numsSize; i++) max_num = MAX(max_num,nums[i]);
    if (max_num == 0) return 0;

    int *cnt = (int*)calloc((max_num+1),sizeof(int));   //构建cnt数组，用于统计各数字出现的次数
    for(int i=0; i<numsSize; i++){
        cnt[nums[i]]++;
    }

    int *point = (int*)calloc((max_num+1),sizeof(int)); //构建point数组，用于统计各数字能拿多少分
    for(int i=0; i<=max_num; i++){
        point[i] = i*cnt[i];
    }

    int a=0, b=point[1], earn=0;                        //动态规划条件初始化（初始条件），处理打家劫舍问题
    for(int i=2; i<=max_num; i++){
        earn = MAX(b,a+point[i]);                       //状态转移方程
        a = b;
        b = earn;
    }
    
    
    free(cnt);                                          //别忘了释放内存
    free(point);

    return b;
}