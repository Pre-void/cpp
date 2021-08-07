#include <stdlib.h>
#include <stdio.h>
#define MAXN 10001
#define MAXM 101
char Number[MAXN][14];
char type[MAXN][14];
int Mark[MAXN];
int M[MAXM];

int less(char a[],char b[]){
    if (a[0]<b[0])
    {
        return 1;
    }else if (a[0]==b[0])
    {
        for (int i = 1; i < 4; i++)
        {
            if (a[i]<b[i])
            {
                return 1;
            }else if (a[i]>b[i])
            {
                return 0;
            }
        }
        for (int j = 4; j < 10; j++)
        {
            if (a[j]<b[j])
            {
                return 1;
            }else if (a[j]>b[j])
            {
                return 0;
            }
        }
        for (int k = 10; k < 13; k++)
        {
            if (a[k]<b[k])
            {
                return 1;
            }else if (a[k]>b[k])
            {
                return 0;
            }   
        }     
    }else{
        return 0;
    }
}

void exch(char arr[][14],int i,int j){
    char temp[14];
    for (int k = 0; k < 14; k++)
    {
        temp[k] = arr[i][k];
    }
    for (int k = 0; k < 14; k++)
    {
        arr[i][k] = arr[j][k];
    }
    for (int k = 0; k < 14; k++)
    {
        arr[j][k] = temp[k];
    }
    int temp1 = Mark[i];
    Mark[i] = Mark[j];
    Mark[j] = temp1;
}

int partition(char arr[][14],int low,int high){
    int i = low,j = high+1;
    char temp[14];
    for (int k = 0; k < 14; k++)
    {
        temp[k] = arr[low][k];
    }
    while (1)
    {
        while (less(arr[++i],temp)) if(i==high) break;
        while (less(temp,arr[--j])) if(j==low) break;
        if (j<=i)
        {
            break;
        }
        exch(arr,i,j);
    }
    exch(arr,low,j);
    return j;
}

void QuickSort(char arr[][14],int low,int high){
    if (high<=low)
    {
        return;
    }
    int j = partition(arr,low,high);
    QuickSort(arr,low,j-1);
    QuickSort(arr,j+1,high);
    
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s",&Number[i]);
        scanf("%d",&Mark[i]);
    } 
    for (int i = 0; i < m; i++)
    {
       scanf("%d",&M[i]);
       scanf("%s",&type[i]);
    }    
    QuickSort(Number,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n",Number[i],Mark[i]);
    }
    

    system("pause");
    return 0;
}