#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int MAXV = 100;;
int numberT[MAXV][MAXV]={{0},{0,5},{0,8,3},{0,12,7,16},{0,4,10,11,6},{0,9,5,3,9,4}};
int number[MAXV];
int dp[MAXV][MAXV];
int nextT[MAXV];
int maxValue = 0;
void init(int n){

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            number[i*(i-1)/2+j] = numberT[i][j];
        }
    }

    
    for (int i = n,j=1; j <= n; j++)
    {
        dp[i][j] = numberT[i][j];
    }
    for (int i = n-1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (dp[i+1][j]>=dp[i+1][j+1])
            {
                nextT[i*(i-1)/2+j] = i*(i+1)/2+j;
            }else{
                nextT[i*(i-1)/2+j] = i*(i+1)/2+j+1;
            }
            
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+numberT[i][j];
        }
    }
}

void DFS(int depth,int x,int y,int sum){
    if (depth>5)
    {
        if (sum>maxValue)
        {
            maxValue = sum;
        }
        
        return;
    }
    DFS(depth+1,x+1,y,sum+numberT[x+1][y]);
    DFS(depth+1,x+1,y+1,sum+numberT[x+1][y+1]);
    
}

int main(){
    /**
    int n;
    scanf("%d",&n);
    init(n);
    printf("%d\n",dp[1][1]);
    int x = 1;
    while (number[x]!=0)
    {
        printf("%d --> ",number[x]);
        x = nextT[x];
    }**/
    DFS(1,1,1,numberT[1][1]);
    printf("%d\n",maxValue);
    system("pause");
    return 0;
    
}