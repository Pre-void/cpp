#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

const int maxn = 100;
int m,n;
char matrix[maxn][maxn];
bool isValid[maxn][maxn] = {false};
struct node
{
    int x,y;
    int step;
    node(int _x,int _y){
        x = _x;
        y = _y;
    }
    node(){};
}S,T,Node;
int X[4] = {1,0,-1,0};
int Y[4] = {0,1,0,-1};

bool judge(int x,int y){
    if (x>=m||x<0||y>=n||y<0)
    {
        return false;
    }
    if (matrix[x][y]=='*'||isValid[x][y]==true)
    {
        return false;
    }
    return true;
    
}
int BFS(){
    queue<node> queue;
    queue.push(S);
    isValid[S.x][S.y] = true;
    while (!queue.empty())
    {
        node top = queue.front();
        queue.pop();
        if (top.x==T.x&&top.y==T.y)
        {
            return top.step;
        }
        for (int i = 0; i < 4; i++)
        {
            int newX = top.x+X[i];
            int newY = top.y+Y[i];
            if (judge(newX,newY))
            {
                Node.x = newX;
                Node.y = newY;
                Node.step = top.step+1;
                queue.push(Node);
                isValid[newX][newY] = true;
            }
            
        }
        
    }
    return -1;
}

int main(){
    scanf("%d%d",&m,&n);
    for (int i = 0; i < m; i++)
    {
        getchar();
        for (int j = 0; j < n; j++)
        {
            scanf("%c",&matrix[i][j]);
        }
    }
    scanf("%d%d%d%d",&S.x,&S.y,&T.x,&T.y);
    S.step = 0;
    printf("%d",BFS());
    system("pause");
    return 0;
}