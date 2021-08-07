#include <stdio.h>
#include <stdlib.h>

#define MAXV 1001
int arr[MAXV];

int less(int x,int y){
    if (x < y)
    {
        return 1;
    }else{
        return 0;
    }
}

void exch(int arr[],int x,int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int partition(int arr[],int low,int high){
    int i = low,j = high+1;
    int temp = arr[low];
    while (1)
    {
        while (less(arr[++i],temp)) if(i == high) break;
        while (less(temp,arr[--j])) if(j == low) break;
        printf("i->%d j->%d\n",i,j);
        printf("----------\n");
        if (i >= j)
        {
            break;
        }
        exch(arr,i,j);
    }
    exch(arr,low,j);
    return j;
}

void  QuickSort(int arr[],int low,int high){
    if (high <= low)
    {
        return;
    }
    int j = partition(arr,low,high);
    QuickSort(arr,low,j-1);
    QuickSort(arr,j+1,high); 
}

int main(){
    for (int i = 0; i < 3; i++)
    {
        scanf("%d",&arr[i]);
    }
    QuickSort(arr,0,2);
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n",arr[i]);
    }
    system("pause");
    return 0;
}