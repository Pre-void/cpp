//记忆化搜索
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAXV = 10000006;
int dp[MAXV];
int Fib(int n){
    if (n==1||n==0)
    {
        return 1;
    }else{
        return Fib(n-1)+Fib(n-2);
    }
}

int Fib_Opt(int n){
    if (n==0||n==1)
    {
        return 1;
    }else if (dp[n]!=-1){
        return dp[n];
    }else{
        dp[n] = Fib(n-1)+Fib(n-2);
        return dp[n];
    }  
}
    


int main(){
    
    memset(dp,-1,sizeof(dp));
    int n;
    scanf("%d",&n);
    int time1 = clock();
    int result1 = Fib(n);
    int time2 = clock();
    int time3 = clock();
    int result2 = Fib_Opt(n);
    int time4 = clock();
    printf("%d,time1-time2=%d\n",result1,time1-time2);
    printf("%d,time3-time4=%d\n",result2,time3-time4);
    system("pause");
    return 0;
}