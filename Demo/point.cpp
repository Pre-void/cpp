#include <stdlib.h>
#include <stdio.h>

int main(){
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
        printf("%d ",arr[i]);
    }
    printf("\n");
    int* p = arr;
    p++;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("%d",*p);
    system("pause");
    return 0;
}