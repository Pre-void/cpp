#include <stdio.h>
#include <stdlib.h>
#define maxn 100001

int array[maxn];
int leftBig[maxn];
int result[maxn];
int main(){
    int N;
    int bigL = 0,bigR,cnt=0;
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&array[i]);
    }
    
    for (int i = 1; i < N; i++)
    {
        if (array[i-1]>bigL)
        {
            bigL = array[i-1];
        }
        leftBig[i] = bigL;        
    }
    
    if (array[N-1]>leftBig[N-1]) result[cnt++] = array[N-1];

    bigR = array[N-1];
    for (int i = N-2; i >= 0; i--)
    {
        if (array[i+1]<bigR)
        {
            bigR = array[i+1];
        }
    
        if (array[i]>leftBig[i]&&array[i]<bigR)
        {
            result[cnt++] = array[i];
        }
        
    }
    printf("%d\n",cnt);
    if (cnt>0)
    {    
        for (int i = cnt-1; i >= 0; i--)
        {
            if (i==0)
            {
                printf("%d",result[i]);
            }else{
                printf("%d ",result[i]);
            }
        }
    }

    

    system("pause");
    return 0;
}