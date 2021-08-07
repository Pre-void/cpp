#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
const int maxn = 100;
int matrix[maxn][maxn];
bool isValid[maxn][maxn] = {false};
int X[4] = {1,0,-1,0};
int Y[4] = {0,1,0,-1};
int m,n;
struct node
{
    int x,y;
    node(int _x,int _y){
        x = _x;
        y = _y;
    }
    node(){}
}Node;
bool judge(int x,int y){
    if (x>=m||x<0||y>=n||y<0)
    {
        return false;
    }
    if (isValid[x][y]==true||matrix[x][y]==0)
    {
        return false;
    }
    return true;
}

void BFS(int x,int y){
    queue<node> queue;
    Node.x = x,Node.y = y;
    queue.push(Node);
    isValid[x][y] == true;
    while (!queue.empty())
    {
        node top = queue.front();
        queue.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = top.x+X[i];
            int newY = top.y+Y[i];
            if (judge(newX,newY))
            {
                isValid[newX][newY] = true;
                queue.push(node(newX,newY));
            }
            
        }
        
    }
    
}

int main(){
    scanf("%d%d",&m,&n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
        
    }
    int result = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j]==1&&isValid[i][j]==false)
            {
                result++;
                BFS(i,j);
            }
            
        }
        
    }
    printf("%d\n",result);
    system("pause");
    return 0;
}