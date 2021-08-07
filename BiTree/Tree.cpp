#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 100;
struct node
{
    int data;
    vector<int> child;
}Node[maxn];
int index = 0;
int newNode(int x){
    Node[index].data = x;
    Node[index].child.clear();
    return index++;
}

void PreOrder(int root){
    printf("%d",Node[root].data);
    for (int i = 0; i < Node[root].child.size(); i++)
    {
        PreOrder(Node[root].child[i]);
    }
}
void LayerOrder(int root){
    queue<int> queue;
    queue.push(root);
    while (!queue.empty())
    {
        int top = queue.front();
        queue.pop();
        printf("%d",top);
        for (int i = 0; i < Node[top].child.size(); i++)
        {
            queue.push(Node[top].child[i]);
        }
        
    }
    
}