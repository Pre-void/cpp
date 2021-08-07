//最大连续子序列和
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int MAXV = 100006;
int A[MAXV],dp[MAXV];

int main(){
    int n,maxValue=0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (i==0)
        {
            dp[0] = A[0];
        }else{
            dp[i] = max(dp[i-1]+A[i],A[i]);
        }     
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i]>maxValue)
        {
            maxValue = dp[i];
        }
    }
    printf("%d\n",maxValue);
    system("pause");
    return 0;
}