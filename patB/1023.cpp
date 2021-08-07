#include <stdio.h>
#include <stdlib.h>
#define MAXV 100000
int n,cnt=0,num0=0;
int result [MAXV];

int main(){
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&n);
        if (i==0)
        {
            num0 = n;
        }
        
        for (int j = 0; j < n; j++)
        {
            result[cnt++]=i;
        }
    }
    
}