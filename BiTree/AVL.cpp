#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct node
{
    int data,height;
    node* lchild;
    node* rchild;
};

node* newNode(int v){
    node* root = new node;
    root->data = v;
    root->height = 1;
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
}

int getHeight(node* root){
    if (root==NULL)
    {
        return 0;
    }
    return root->height;
}

int getBalanceFactor(node* root){
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* root){
    root->height = max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

node* search(node* root,int x){
    if (root==NULL)
    {
        return NULL;
    }
    if (root->data==x)
    {
        return root;
    }else if (root->data > x)
    {
        return search(root->rchild,x);
    }else{
        return search(root->lchild,x);
    }
}

void L(node* &root){
    node* right = root->rchild;
    root->rchild = right->lchild;
    right->lchild = root;
    updateHeight(root);
    updateHeight(right);
    root = right;
}

void R(node* &root){
    node* left = root->lchild;
    root->lchild = left->rchild;
    left->rchild = root;
    updateHeight(root);
    updateHeight(left);
    root = left;
}

void insert(node* &root,int x){
    if (root==NULL)
    {
        root = newNode(x);
        return;
    }
    if (root->data > x)
    {
        insert(root->lchild,x);
        updateHeight(root);
        if (getBalanceFactor(root)==2)
        {
            if (getBalanceFactor(root->lchild)==1)
            {
                R(root);
            }else if (getBalanceFactor(root->lchild)==-1)
            {
                L(root->lchild);
                R(root);
            }
        }
    }else{
        insert(root->rchild,x);
        updateHeight(root);
        if (getBalanceFactor(root)==-2)
        {
            if (getBalanceFactor(root->rchild)==1)
            {
                R(root->rchild);
                L(root);
            }else if (getBalanceFactor(root->rchild)==-1)
            {
                R(root);
            }
        }
        
    }
    
}