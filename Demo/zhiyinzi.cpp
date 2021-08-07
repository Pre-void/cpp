#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const int maxn = 101;
bool isPrime[maxn] = {false};
int Prime[maxn],num = 0;
 struct factor
 {
     int x;
     int cnt;
 }fac[10];
 
 void Find_Prime(){
     for (int i = 2; i < maxn; i++)
     {
         if (isPrime[i]==false)
         {
             Prime[num++] = i;
             for (int j = i+i; j <= maxn; j+=i)
             {
                 isPrime[j] = true;
             }
         }
     }
 }

 void get_Factor(int n){
     int x=n,sqr = (int)sqrt(x*1.0);
     for (int i = 0; i < maxn&&Prime[i]<=sqr; i++)
     {
        //  int n = x;
         if (x%Prime[i]==0)
         {
             fac[num].x = Prime[i];
             fac[num].cnt = 0;
             while (x%Prime[i]==0)
             {
                 fac[num].cnt++;
                 x /= Prime[i];
             }
             num++;
         }
         if (x==1)
         {
             break;
         }
     }    
     if (x!=1)
     {
         fac[num].x = x;
         fac[num++].cnt = 1;                                                                                                                 
     }
      
 }

 int main(){
     int x;
     scanf("%d",&x);
     Find_Prime();     
     get_Factor(x);
     printf("%d\n",num);
     for (int i = 0; i < maxn; i++)
     {
         for (int j = 0; j < fac[i].cnt; j++)
         {
             printf("*%d",fac[i].x);
         }
     }
     system("pause");
     return 0;
     
 }