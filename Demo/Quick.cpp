#include <stdio.h>
#include <stdlib.h>

#define maxv 1001
int arr[maxv];

bool less(int i,int j){
    if (i<j)
    {
        return true;
    }else{
        return false;
    }
}

void exch(int arr[],int x,int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int partition(int arr[],int low,int high){
    int i = low,j = high+1;
    int v = arr[low];
    while (true)
    {
        while (less(arr[++i],v))
        {
            if (i==high)
            {
                break;
            }
        }
        while (less(v,arr[--j]))
        {
            if (j==low)
            {
                break;
            }
        }
        if (i>=j)
        {
            break;
        }
        exch(arr,i,j);
    }
    exch(arr,low,j);
    return j;
}

void QuickSort(int arr[],int low,int high){
    if (low >= high)
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