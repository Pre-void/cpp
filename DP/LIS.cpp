#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int MAXV = 100006;
int A[MAXV],dp[MAXV];

int main(){
    int n,result=0,ans;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        ans = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[i]>=A[j]&&dp[j]+1>ans)
            {
                ans = dp[j]+1;
            }
        }
        dp[i] = ans;
        if (ans>result)
        {
            result = ans;
        }
    }
    printf("%d\n",result);
    system("pause");
    return 0;
}