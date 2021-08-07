#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXV 100006
char A[MAXV],B[MAXV];
int dp[MAXV][MAXV];

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    scanf("%s",A+1);
    getchar();
    scanf("%s",B+1);
    int lengthA = strlen(A+1);
    int lengthB = strlen(B+1);
    // printf("%c   %c\n",A[0],A[1]);
    // printf("%d %d",lengthA,lengthB);
    for (int i = 0; i < lengthA; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i < lengthB; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= lengthA; i++)
    {
        for (int j = 1; j <= lengthB;j++)
        {
            if (A[i]==B[j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }else if(dp[i-1][j]>=dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    printf("%d\n",dp[lengthA][lengthB]);
    system("pause");
    return 0;
}