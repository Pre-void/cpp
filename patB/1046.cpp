#include <stdio.h>
#include <stdlib.h>
int cnt1=0,cnt2=0,sum;
int main(){
    int N;
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        int A1,A2,B1,B2;
        scanf("%d %d %d %d",&A1,&A2,&B1,&B2);
        sum = A1+B1;
        if (sum==A2&&sum!=B2)
        {
            cnt2++;
        }else if (sum==B2&&sum!=A2)
        {
            cnt1++;
        }
    }
    
    printf("%d %d\n",cnt1,cnt2);
    system("pause");
    return 0;
}