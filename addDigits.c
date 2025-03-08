#include <stdio.h>
int addDigits(int num){
    int sum=0;
    while(num != 0){
        sum += (num % 10);
        num /= 10;
    }
    if(sum%10 == sum) return sum;
    else return addDigits(sum);
}
void main(){
    int num = 38;
    printf("%d",addDigits(num));
}