#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
int pre[5] = {3,2,1,4,5};
int in[5] = {1,2,3,4,5};
struct node
{
    int data;
    node* lchild;
    node* rchild;
};

node* newNode(int v){
    node* Node = new node;
    Node->data = v;
    Node->lchild = NULL;
    Node->rchild = NULL;
    return Node;
}

void update(node* Node,int oldData,int newData){
    if (Node==NULL)
    {
        return;
    }
    if (Node->data==oldData)
    {
        Node->data = newData;
    }
    update(Node->lchild,oldData,newData);
    update(Node->rchild,oldData,newData);
}

void insert(node* &Node,int x){
    if (Node==NULL)
    {
        Node = newNode(x);
        return;
    }
    if (x<=Node->data)
    {
        insert(Node->lchild,x);
    }else{
        insert(Node->rchild,x);
    }
    
}

node* create(int data[],int n){
    node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        insert(root,data[i]);
    }
    return root;
}

void preorder(node* root){
    if (root==NULL)
    {
        return;
    }
    printf("%d",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void layerOrder(node* root){
    queue<node*> queue;
    queue.push(root);
    while (!queue.empty())
    {
        node* top = queue.front();
        queue.pop();
        printf("%d",top->data);
        if (top->lchild!=NULL) queue.push(top->lchild);
        if (top->rchild!=NULL) queue.push(top->rchild);  
    }   
}

node* recreate(int preL,int preR,int inL,int inR){
    if (inL>inR)
    {
        return NULL;
    }
    // printf("%d\n",preL);
    node* root = newNode(pre[preL]);
    // node* root = new node;
    // root->data = pre[preL];
    int k;
    for (k = inL; k <= inR; k++)
    {
        if (in[k]==pre[preL])
        {
            break;
        }
        
    }
    int numberLeft = k-inL;

    root->lchild = recreate(preL+1,preL+numberLeft,inL,k-1);
    root->rchild = recreate(preL+numberLeft+1,preR,k+1,inR);
    return root;

}
int main(){
    /**生成一棵树
    int n,x,y;
    scanf("%d",&n);
    int data[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&data[i]);
    }
    node* root = create(data,n);
    **/
    //先序遍历
    // preorder(root);
    // printf("\n");
    // scanf("%d%d",&x,&y);
    // update(root,x,y);
    // preorder(root);
    // printf("\n");676y6
    //层次遍历
    // layerOrder(root);
    /**先序中序遍历生成树**/
    node* root = recreate(0,4,0,4);
    layerOrder(root);
    system("pause");
    return 0;
}