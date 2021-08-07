#include <stdio.h>
#include <stdlib.h>
#include <queue>
const int MAXV = 1000;
const int INF = 100000000;
using namespace std;
int n;
int G[MAXV][MAXV];
bool vis[MAXV] = {false};//是否被访问
bool inq[MAXV] = {false};//是否入队

void DFS(int u,int depth){
    vis[u] = true;
    //可对u的操作
    printf("%d %d\n",u,depth);
    //下面对所有从u出发能到达的分支顶点进行枚举
    for (int i = 0; i < n; i++)
    {
        if (vis[i]==false&&G[u][i]!=INF)
        {
            DFS(i,depth+1);
        }
    }
}

void DFSTrave(){
    for (int i = 0; i < n; i++)
    {
        if (vis[i]==false)
        {
            DFS(i,1);
        }
    }
}

void BFS(int u){
    queue<int> queue;
    queue.push(u);
    inq[u] = true;
    while (!queue.empty())
    {
        int top = queue.front();
        queue.pop();
        printf("%d",top);
        for (int i = 0; i < n; i++)
        {
            if (inq[i]==false&&G[u][i]!=false)
            {
                queue.push(i);
                inq[i] = true;
            }
        }
    }
}

void BFSTrave(){
    for (int i = 0; i < n; i++)
    {
        if (inq[i]==false)
        {
            BFS(i);
        }
        
    }
    
}

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&G[i][j]);
        }
    }
    // DFSTrave();
    BFSTrave();
    system("pause");
    return 0;
}
 