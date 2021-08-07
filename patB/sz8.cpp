#include <stdlib.h>
#include <stdio.h>

int main(){
    int year,nowY = 2021,date = 9;
    scanf("%d",&year);
    if (year>=nowY)
    {
        for (int i = 2022; i <= year; i++)
        {
            if (i%4==0&&i%100!=0||i%400==0)
            {
                date -= 2;
            }else{
                date -= 1;
            }
            date<=7?date+=7:date;
        }
    }else{
        for (int i = 2021; i > year; i--)
        {
            if (i%4==0&&i%100!=0||i%400==0)
            {
                date +=2;
            }else{
                date +=1;
            }
            date>=14?date-=7:date;
        }
    }
    printf("%d-5-%d\n",year,date);
    system("pause");
    return 0;
}