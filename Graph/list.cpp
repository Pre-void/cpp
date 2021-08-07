#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
int n;
const int MAXV = 1000;
const int INF = 100000000;
bool vis[MAXV] = {false};
bool inq[MAXV] = {false};
vector<int> Adj[MAXV];

void DFS(int u,int depth){
    vis[u] = true;
    //可对u进行操作
    printf("%d %d\n",u,depth);
    for (int i = 0; i < Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        if (vis[v]==false)
        {
            DFS(v,depth+1);
        }
    }
} 

void DFSTrave(){
    for (int u = 0; u < n; u++)
    {
        if (vis[u]==false)
        {
            DFS(u,1);
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
        printf("%d\n",top);
        for (int i = 0; i < Adj[top].size(); i++)
        {
            int v = Adj[top][i];
            printf("*******************%d\n",inq[v]);
            if (inq[v]==false)
            {
                printf("hhhhhhhhhhhhhhhhhh\n");
                queue.push(v);
                inq[v] = true;
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
    Adj[0].push_back(1);
    Adj[0].push_back(4);
    Adj[1].push_back(0);
    Adj[1].push_back(2);
    Adj[1].push_back(4);
    Adj[2].push_back(1);
    Adj[2].push_back(3);
    Adj[3].push_back(2);
    Adj[3].push_back(4);
    Adj[4].push_back(0);
    Adj[4].push_back(1);
    Adj[4].push_back(3);
    // DFSTrave();
    BFSTrave();
    system("pause");
    return 0;
    
}