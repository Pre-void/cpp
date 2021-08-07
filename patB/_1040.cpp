#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int maxn = 1000006;
char str[maxn];
int countP[maxn];
void calP(char str[],int len){
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        countP[i] = count;
        if (str[i]=='P')
        {
            count++;
        }
    }
}
int main(){
    int num=0;
    scanf("%s",str);
    int len = strlen(str);
    calP(str,len);
    int countT=0;
    for (int i = len-1; i > 0; i--)
    {
        if (str[i]=='A')
        {
            num = num+countP[i]*countT;
        }else if (str[i]=='T')
        {
            countT++;
        }
    }
    printf("%d",num);
    system("pause");
    return 0;

}