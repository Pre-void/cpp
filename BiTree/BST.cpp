#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    node* lchild;
    node* rchild;
};

node* newNode(int x){
    node* root = new node;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
}

void search(node* root,int x){
    if (root==NULL)
    {
        return;
    }
    if (root->data==x)
    {
        printf("%d",root->data);
    }else if (root->data>x)
    {
        search(root->rchild,x);
    }else{
        search(root->lchild,x);
    }
}

void insert(node* &root,int x){
    if (root==NULL)
    {
        root = newNode(x);
        return;
    }
    if (root->data==x)
    {
        return;
    }else if(root->data>x){
        insert(root->lchild,x);
    }else{
        insert(root->rchild,x);
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

node* findMax(node* root){
    while (root->rchild!=NULL)
    {
        root = root->rchild;
    }
    return root;
}

node* findMin(node* root){
    while (root->lchild!=NULL)
    {
        root = root->lchild;
    }
    return root;
}

void deleteNode(node* &root,int x){
      if (root==NULL)
      {
          return;
      }
      if (root->data==x)
      {
          if (root->lchild==NULL&&root->rchild==NULL)
          {
              root = NULL;
          }else if (root->rchild!=NULL)
          {
               node* temp = findMax(root->lchild);
               root->data = temp->data;
               deleteNode(root->lchild,temp->data);
          }else{
              node* temp = findMin(root->rchild);
              root->data = temp->data;
              deleteNode(root->rchild,temp->data);
          }
      }else if (root->data > x)
      {
          deleteNode(root->rchild,x);
      }else{
          deleteNode(root->lchild,x);
      }
      
      
      
}