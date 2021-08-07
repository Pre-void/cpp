#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXV 100006
char S[MAXV];
int dp[MAXV][MAXV];

int main(){
    int length,result=1;
    scanf("%s",S);
    // getchar();
    length = strlen(S);
    for (int i = 0; i < length; i++)
    {
        dp[i][i] = 1;
        if (i+1<length&&S[i]==S[i+1])
        {
            dp[i][i+1] = 1;
            result = 2;
        }
    }

    for (int i = 3; i <= length; i++)
    {
         for (int j = 0; j+i-1 < length; j++)
         {
             if (S[j]==S[j+i-1]&&dp[j+1][j+i-2]==1)
             {
                 dp[j][j+i-1] = 1;
                 result = i;
             }     
         }
    }

    printf("%d\n",result);
    system("pause");
    return 0;
}