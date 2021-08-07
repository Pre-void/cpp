#include <stdio.h>
#include <stdlib.h>
const int maxn = 30;
int n,V,maxValue = 0;
int w[maxn],c[maxn];
/**
void DFS(int index,int sumW,int sumC){
    if (index==n)
    {
        if (sumW<=V && sumC>maxValue)
        {
            maxValue = sumC;
        }
        return;
    }
    DFS(index+1,sumW,sumC);
    DFS(index+1,sumW+w[index],sumC+c[index]);   
}**/

void DFS(int index,int sumW,int sumC){
    if (index==n)
    {
        return;
    }
    DFS(index+1,sumW,sumC);
    if (sumW+w[index]<=V&&sumC+c[index]>maxValue)
    {
        maxValue = sumC+c[index];
    }
    DFS(index+1,sumW+w[index],sumC+c[index]);
    
}

int main(){
    scanf("%d%d",&n,&V);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&w[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&c[i]);
    }
    DFS(0,0,0);
    printf("%d\n",maxValue);
    system("pause");
    return 0;
}