#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;
const int maxn = 30;
int n,k,x,maxSumsqu = -1,A[maxn];
vector<int> ans,temp;

void DFS(int index,int nowK,int sum,int sumSqu){
    if (nowK==k&&sum==x)
    {
        if (sumSqu>maxSumsqu)
        {
            maxSumsqu = sumSqu;
            ans = temp;
        }
        return;
    }
    if (index==n||nowK>k||sum>x)
    {
        return;
    }
    
    temp.push_back(A[index]);
    DFS(index+1,nowK+1,sum+A[index],sumSqu+A[index]*A[index]);
    temp.pop_back();
    DFS(index+1,nowK,sum,sumSqu);
}

int main(){
    scanf("%d%d%d",&n,&k,&x);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    DFS(0,0,0,0);
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
    {
        printf("%d ",*it);
    }
    system("pause");
    return 0;
}