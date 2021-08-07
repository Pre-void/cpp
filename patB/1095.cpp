#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXV 1001;
int cnt = 0;
int result2[2];
struct examinee
{
    char number[14];
    char level;
    int room;
    int date;
    char identifier[3];
    int score;
}E[10001],array[10001];

struct Room_Count
{
    int room;
    int cnt;
}RC[10001];

void exch1(examinee array[],int i,int j){
    examinee temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void exch2(Room_Count array[],int i,int j){
    Room_Count temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int partition1(examinee array[],int low,int high){
    int i = low,j = high+1;
    examinee v = array[low];
    while (1)
    {
        while(array[++i].score < v.score||(array[i].score==v.score&&strcmp(array[i].number,v.number)>0)) if(i == high) break;
        while(v.score < array[--j].score||(array[j].score==v.score&&strcmp(v.number,array[j].number)>0)) if(j == low) break;
        if (i>=j)
        {
            break;
        }
        exch1(array,i,j);
    }
    exch1(array,low,j);
    return j;
}

int partition2(Room_Count array[],int low,int high){
    int i = low,j = high+1;
    Room_Count v = array[low];
    while (1)
    {
        while(array[++i].cnt < v.cnt||(array[i].cnt==v.cnt&&array[i].room>v.room)) if(i == high) break;
        while(v.cnt < array[--j].cnt||(array[j].cnt==v.cnt&&v.room>array[j].room)) if(j == low) break;
        if (i>=j)
        {
            break;
        }
        exch2(array,i,j);
    }
    exch2(array,low,j);
    return j;
}

void QuickSort1(examinee array[],int low,int high){
    if (high <= low)
    {
        return;
    }
    int j = partition1(array,low,high);
    QuickSort1(array,low,j-1);
    QuickSort1(array,j+1,high);
}

void QuickSort2(Room_Count array[],int low,int high){
    if (high <= low)
    {
        return;
    }
    int j = partition2(array,low,high);
    QuickSort2(array,low,j-1);
    QuickSort2(array,j+1,high);
}
int convert(char arr[],int start,int end){
    int result=0;
    for (int i = start; i < end; i++)
    {
        result = result*10 + (arr[i]-'0');
    }
    return result;
}
int Position(Room_Count arr[],int cnt,int room){
    for (int i = 0; i < cnt; i++)
    {
        if (arr[i].room==room)
        {
            return i;
        }
    }
    return -1;
}

void generate1(char level,int N){
    cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (E[i].level==level)
        {
            for (int j = 0; j < 14; j++)
            {
            array[cnt].number[j] = E[i].number[j];
            }  
            array[cnt].level = E[i].level;
            array[cnt].room = E[i].room;
            array[cnt].date = E[i].date;
            for (int k = 0; k < 3; k++)
            {
                array[cnt].identifier[k] = E[i].identifier[k];
            }
            array[cnt].score = E[i].score;
            cnt++;
        }
    }
    QuickSort1(array,0,cnt-1);
}

void generate2(int room,int N){
    for (int i = 0; i < N; i++)
    {
        if (E[i].room==room)
        {
            result2[0]++;
            result2[1]+=E[i].score;
        } 
    }
}

void generate3(int date,int N){
    cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (E[i].date==date)
        {
            int position = Position(RC,cnt,E[i].room);
            if (position!=-1)
            {
                RC[position].cnt++;
            }else{
                RC[cnt].cnt=1;
                RC[cnt].room = E[i].room;
                cnt++;
            }
        }
    }
    QuickSort2(RC,0,cnt-1);
}


int main(){
    int N,M;
    char number[14],request[M][10];
    int type[M],score;
    scanf("%d %d",&N,&M);
    for (int i = 0; i < N; i++)
    {
        scanf("%s",&E[i].number);
        scanf("%d",&score);
        E[i].level = E[i].number[0];
        E[i].room = convert(E[i].number,1,4);
        E[i].date = convert(E[i].number,4,10);
        for (int k = 10; k < 13; k++)
        {
            E[i].identifier[k-10] = E[i].number[k];
        }        
        E[i].score = score;
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d",&type[i]);
        scanf("%s",&request[i]);

    }
    for (int i = 0; i < M; i++)
    {
        if (type[i]==1)
        {
            generate1(request[i][0],N);
            if (cnt==0)
            {
                printf("Case 4: %d %c\n",type[i],request[i][0]);
                printf("NA\n");
            }else{
            printf("Case 1: %d %c\n",type[i],request[i][0]);
            for (int j = cnt-1; j >= 0; j--)
            {
                printf("%c%d%d%s %d\n",array[j].level,array[j].room,array[j].date,array[j].identifier,array[j].score);
            }
            }
        }else if (type[i]==2)
        {
            int room = convert(request[i],0,3);
            generate2(room,N);
            if (result2[0]==0)
            {
                printf("Case 4: %d %d\n",type[i],room);
                printf("NA\n");
            }else{
                printf("Case 2: %d %d\n",type[i],room);
                printf("%d %d\n",result2[0],result2[1]);
                result2[0]=0,result2[1]=0;
            }
        }else
        {
            int date = convert(request[i],0,6);
            generate3(date,N);
            if (cnt==0)
            {
                printf("Case 4 %d %d\n",type[i],date);
                printf("NA\n");
            }else
            {
                printf("Case 3: %d %d\n",type[i],date);
                for (int k = cnt-1; k >= 0; k--)
                {
                    printf("%d %d\n",RC[k].room,RC[k].cnt);
                }
            }
        }
    }
    
    
    system("pause");
    return 0;
}


