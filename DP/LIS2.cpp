#include <stdio.h>
#include <stdlib.h>
#define MAXV 100006
int A[MAXV],d[MAXV];

int main(){
    int n,length=-1;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    d[++length] = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i]>=d[length])
        {
            d[++length] = A[i];
        }else if (A[i]<d[length]&&A[i]>d[length-1]&&length-1>0)
        {
            d[length] = A[i];
        }  
    }
    printf("%d\n",length+1);
    for (int i = 0; i <=length; i++)
    {
        printf("%d ",d[i]);
    }
    system("pause");
    return 0;
}