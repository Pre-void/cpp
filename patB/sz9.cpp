#include <stdio.h>
#include <stdlib.h>
#define maxn 27
char P[maxn];
int n,hashTable[maxn];
char letter[27];
void generate(int index){
    if (index==n+1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%c",P[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (hashTable[i]==false)
        {
            P[index] = letter[i];
            hashTable[i] = true;
            generate(index+1);
            hashTable[i] = false;
        }
    }
}


int main(){
    for (int i = 'a'; i <= 'z'; i++)
    {
        letter[i-'a'+1] = i;
    }
    scanf("%d",&n);
    generate(1);
    system("pause");
    return 0;
}