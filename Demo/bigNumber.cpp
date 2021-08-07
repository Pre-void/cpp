#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct bigNumber
{
    int d[1000];
    int len;
    char flag;
    bigNumber(){
        memset(d,0,sizeof(d));
        len = 0;
        flag = '+';
    }
};

int compare(bigNumber b1,bigNumber b2){
    if (b1.len>b2.len)
    {
        return 1;     
    }else if (b1.len < b2.len)
    {
        return -1;
    }else{
    {
        for (int i = 0; i < b1.len; i++)
        {
            if (b1.d[i] > b2.d[i])
            {
                return 1;
            }else if (b1.d[i] < b2.d[i])
            {
                return -1;
            }
        }
        
    }
    return 0;
}
}

bigNumber change(char str[]){
    int len = strlen(str);
    bigNumber b;
    for (int i = 0; i < len; i++)
    {
        b.d[i] = str[len-i-1] - '0';
    }
    b.len = len;
    return b;
}

bigNumber add(bigNumber b1,bigNumber b2){
    bigNumber result;
    int carry = 0;
    for (int i = 0; i < b1.len||i < b2.len; i++)
    {
        int temp = b1.d[i]+b2.d[i]+carry;
        result.d[result.len++] = temp%10;
        carry = temp/10;
    }
    if (carry!=0)
    {
        result.d[result.len++] = carry;
    }
    return result;
}

bigNumber sub(bigNumber b1,bigNumber b2){
    bigNumber result;
    for (int i = 0; i < b1.len||i<b2.len; i++)
    {
        if (b1.d[i]<b2.d[i])
        {
            b1.d[i+1]--;
            b2.d[i]+=10;
        }
        result.d[result.len++] = b1.d[i] - b2.d[i];
    }
    while (result.len-1>=1 && result.d[result.len-1]==0)
    {
        result.len--;
    }
    return result;
}

int main(){
    char str1[1000],str2[1000];
    scanf("%s",str1);
    scanf("%s",str2);
    bigNumber bign1 = change(str1);
    bigNumber bign2 = change(str2);
    if (compare(bign1,bign2)==1)
    {
        printf("bign1大");
    }else if (compare(bign1,bign2)==-1)
    {
        printf("bign2大");
    }else{
        printf("一样大");
    }
    // bigNumber bign3 = add(bign1,bign2);
    bigNumber bign4 = sub(bign1,bign2);
    printf("length=%d\n",bign4.len);
    for (int i = bign4.len-1; i >= 0; i--)
    {
        printf("%d",bign4.d[i]);
    }
    system("pause");
    return 0;
    
}