#include <stdio.h>
#include <stdlib.h>
int cnt=0;
void Hanoi(int n,char a,char b,char c){
    if (n==1)
    {
        cnt++;
        printf("第 %d 次 %c-->%c\n",cnt,a,c);
    }else{
        Hanoi(n-1,a,c,b);
        cnt++;
        printf("第 %d 次 %c-->%c\n",cnt,a,c);
        Hanoi(n-1,b,a,c);
    }
    
}

int main(){
    Hanoi(4,'a','b','c');
    system("pause");
    return 0;
}