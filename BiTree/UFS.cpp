#include <stdio.h>
#include <stdlib.h>
const int maxn = 100;
int father[maxn];
bool isRoot[maxn];
int findFather(int x){
    while (x!=father[x])
    {
        x = father[x];
    }
    return x;
}

int findFather2(int x){
    if (x!=father[x])
    {
        findFather2(father[x]);
    }else{
        return x;
    }
}

void Union(int x,int y){
    int fatA = findFather(x);
    int fatB = findFather(y);
    if (fatA==fatB)
    {
        return;
    }else{
        father[fatA] = fatB;
    }
}

int findFatherQuick(int x){
    int z = x;
    while (x!=father[x])
    {
        x = father[x];
    }
    while (z!=father[z])
    {
        int temp = z;
        z = father[z];
        father[temp]=x;
    }
}

void init(int x){
    for (int i = 1; i <= x; i++)
    {
        father[i] = i;
        isRoot[i] = false;
    }
}

int main(){
    int m,n,a,b,ans=0;
    scanf("%d%d",&m,&n);
    init(m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&a,&b);
        Union(a,b);
    }
    for (int i = 1; i <= m; i++)
    {
        int temp = findFatherQuick(i);
        isRoot[temp] = true;
    }
    for (int i = 1; i <= m; i++)
    {
        if (isRoot[i])
        {
            ans++;
        }
    }
    printf("%d",ans);
    system("pause");
    return 0;
    
}