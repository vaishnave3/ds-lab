#include "adt.h"
#include<stdio.h>
#include<stdlib.h>

int getHeight(struct avl *node)
{
  if(node==NULL)
  return 0;
  return node->height;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

int getBalance(struct avl *n)
{
  return getHeight(n->left) - getHeight(n->right);
}

struct avl *leftR(struct avl *x)
{
  struct avl *y = x->right;
  struct avl *T2 = y->left;

  y->left = x;
  x->right = T2;

  y->height = 1 +  max(getHeight(y->left), getHeight(y->right));
  x->height = 1 +  max(getHeight(x->left), getHeight(x->right));

  return y;
}

struct avl *rightR(struct avl *y)
{
  struct avl *x = y->left;
  struct avl *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = 1 +  max(getHeight(y->left), getHeight(y->right));
  x->height = 1 +  max(getHeight(x->left), getHeight(x->right));

  return x;
}

struct avl *createNode(int key)
{
  struct avl *node = (struct avl*)malloc(sizeof(struct avl));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}

struct avl *insert(struct avl *node, int key)
{
  if(node==NULL)
  return createNode(key);
  else if(key>node->key) node->right = insert(node->right,key);
  else if(key<node->key) node->left = insert(node->left, key);
  else return node;

  node->height = 1 + max(getHeight(node->left), getHeight(node->right));
  
  int bal = getBalance(node);

  if(bal > 1 && key < node->left->key)
  return rightR(node);

  if(bal < -1 && key > node->right->key)
  return leftR(node);

  if(bal > 1 && key > node->left->key)
  {
    node->left = leftR(node->left);
    return rightR(node);
  }

  if(bal < -1 && key < node->right->key)
  {
    node->right = rightR(node->left);
    return leftR(node);
  }
  return node;
}

void inorder(struct avl* t)
{
  if(t==NULL)
  return;
  printf("%d ",t->key);
  inorder(t->left);
  inorder(t->right);
}

struct avl *level(struct avl *t, int i)
{
  if(i==0)
  printf("%d ", t->key);
  if(t->left!=NULL) level(t->left,i-1);
  if(t->right!=NULL) level(t->right, i-1);
}


void levelorder(struct avl *t)
{
  for(int i=0; i<getHeight(t)+1;i++)
  level(t,i);
}


