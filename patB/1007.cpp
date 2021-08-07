#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXV 1000001
bool isPrime[MAXV];
int Prime[MAXV];
int Num = 0,cnt=0;

void getList(int n){
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i]==false)
        {
            Prime[Num++] = i;
        }
        for (int j = i+i; j < n; j+=i)
        {
            isPrime[j] = true;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    getList(n);
    for (int i = 1; i < Num; i++)
    {
        if (Prime[i]-Prime[i-1]==2)
        {
            cnt++;
        }
        
    }
    printf("%d\n",cnt);
    system("pause");
    return 0;
}