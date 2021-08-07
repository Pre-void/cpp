#include <stdio.h>
#include <stdlib.h>

int main(){
    int cnt=0,a,b;
    while (scanf("%d %d",&a,&b)!=EOF)
    {        
        a *= b;
        if (a==0&&b==0){
            if (cnt==0)
            {
                printf("0 0");
            }
            break;
        }
        b--;
        if (cnt==0)
        {
            printf("%d %d",a,b);
        }else{
            printf(" %d %d",a,b);
        } 
        cnt++;
    }  
    system("pause");
    return 0; 
}