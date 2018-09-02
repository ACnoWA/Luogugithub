/*************************************************************************
	> File Name: 1149.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月15日 星期三 17时04分30秒
 ************************************************************************/


//此题在定界时，可以这样考虑，再０－９中
//只有表示数字１的数量是最少的，即相同位数下，由１组成的数字是所需火柴数
//最少的所以对于题目给的24 减去4之后得20，由数字111和1111框出最多只能表示
//三位数相加，而在三位数中711对应火柴数7,又711是除了111所需火柴数最少的
//所以可知上界为711

#include <stdio.h>

int num[10] = {
    6, 2, 5, 5,
    4, 5, 6, 3,
    7, 6
};

int caclu(int n){
    int sum = 0;
    if(n == 0) return 6;
    while(n){
        sum += num[n % 10];
        n /= 10;
    }
    return sum;
}

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    n -= 4;
    for(int i = 0 ; i <= 711; i++){
        for(int j = 0; j <= 711; j++){
            if (caclu(i) + caclu(j) + caclu(i + j) == n){
                printf("%d + %d = %d\n", i, j, i+j);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}