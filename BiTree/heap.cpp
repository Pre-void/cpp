#include <stdio.h>
#include <stdlib.h>
const int maxn = 100;
int heap[maxn],n=10;

void downAdjust(int x,int high){
    int i = x,j=2*i;
    while (j<=high)
    {
        if (j+1<=high&&heap[j+1]>heap[j])
        {
            j = j+1;
        }
    if (heap[i]<heap[j])
    {
        int temp = heap[i];
        heap[j] = heap[i];
        heap[i] = temp;
        i = j;
        j*=2;
    }else{
        break;
    }
    }  
}
void createHeap(){
    for (int i = n/2;i >= 1;i--)
    {
        downAdjust(i,n);
    }
}

void deleteTop(){
    heap[1] = heap[n--];
    downAdjust(1,n);
}

void upAdjust(int low,int high){
    int i = high,j=i/2;
    while (j>=low)
    {
        if (heap[i]>heap[j])
        {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
            j = i/2;
        }else{
            break;
        }
    }
}
void insert(int x){
    heap[++n] = x;
    upAdjust(1,n);
}