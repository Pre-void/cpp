#include <stdlib.h>
#include <stdio.h>

int N;
double D;
struct moonCake{
    double stock;
    double wholeSale;
    double price;
}Cake[1001];

void exch(moonCake arr[],int x,int y){
    moonCake temp = Cake[x];
    Cake[x] = Cake[y];
    Cake[y] = temp;
}

int partition(moonCake arr[],int low,int high){
    int i = low,j = high+1;
    moonCake temp = arr[low];
    while (1)
    {
        while (arr[++i].price < temp.price) if(i == high) break;
        while (temp.price<arr[--j].price) if(j == low) break;
        if (i >= j)
        {
            break;
        }
        exch(arr,i,j);
    }
    exch(arr,low,j);
    return j;
}

void  QuickSort(moonCake arr[],int low,int high){
    if (high <= low)
    {
        return;
    }
    int j = partition(arr,low,high);

    QuickSort(arr,low,j-1);
    QuickSort(arr,j+1,high); 
}

int main(){

    scanf("%d %lf",&N,&D);
    for (int i = 0; i < N; i++)
    {
        scanf("%lf",&Cake[i].stock);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%lf",&Cake[i].wholeSale);
        Cake[i].price = Cake[i].wholeSale/Cake[i].stock;
    }
    QuickSort(Cake,0,N-1);
    double result = 0;
    for (int i = N-1; i >= 0; i--)
    {
        if (Cake[i].stock >= D)
        {
            result += D*Cake[i].price;
            break;
        }else{
            result += Cake[i].wholeSale;
            D -= Cake[i].stock;
        }
    }
    printf("%.2lf\n",result);
    system("pause");
    return 0;
}