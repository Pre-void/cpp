#include <stdio.h>
#include <stdlib.h>
#define MAXV 10
int array[MAXV];

int main(){
    for (int i = 0; i < MAXV; i++)
    {
        scanf("%d",&array[i]);
    }
    
    for (int i = 1; i < MAXV; i++)
    {
        if (array[i]!=0)
        {
            printf("%d",i);
            array[i]--;
            break;
        }
    }
    for (int i = 0; i < MAXV; i++)
    {
        for (int j = 0; j < array[i]; j++)
        {
            printf("%d",i);
        }
    }
    system("pause");
    return 0;
}