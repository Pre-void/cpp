#include <stdlib.h>
#include <stdio.h>
const int maxn = 101;
bool isPrime[maxn] = {0};
int Prime[maxn],num=0;

void Find_Prime(){
    for (int i = 2; i < maxn; i++)
    {
        if (isPrime[i]==false)
        {
            // printf("%d ",i);
            Prime[num++] = i;
            for (int j = i+i; j < maxn; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }
}

int main(){
    Find_Prime();
    printf("%d\n",num);
    for (int i = 0; i < num; i++)
    {
        printf("%d ",Prime[i]);
    }
    system("pause");
    return 0;
}