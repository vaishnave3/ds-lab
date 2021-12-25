#include "adt.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//insert into bst
struct bst* insert(struct bst* t, int x, char str[])
{
    if(t==NULL)
    {
        struct bst *temp = (struct bst*)malloc(sizeof(struct bst));
        temp->data = x;
        strcpy(temp->s,str);
        temp->left = NULL;
        temp->right = NULL;
        return temp;
        //printf("yes");
    }
    if(x<t->data) t->left = insert(t->left, x, str);
    if(x>t->data) t->right = insert(t->right, x, str);
    return t;
}

void inorder(struct bst* t)
{
  if(t==NULL)
  return;
  inorder(t->left);
  printf("%d %s",t->data, t->s);
  inorder(t->right);
}

struct bst *findmin(struct bst *t)
{
  if(t->left!=NULL)
  return findmin(t->left);
  return t;
}
struct bst *del(struct bst *t, int x)
{
  if(t==NULL)
  return t;
  
  else if(x<t->data) t->left = del(t->left, x);
  else if(x>t->data) t->right = del(t->right, x);
  else
  {
    struct bst *temp;
    if(t->left!=NULL && t->right!=NULL)
    {
      temp = findmin(t->right);
      t->data = temp->data;
      t->right = del(t->right, t->data);
    }
    else
    {
      if(t->right==NULL) temp = t->left;
      if(t->left==NULL) temp = t->right;
      free(t);
      return temp;
    }
  }
}

int getheight(struct bst *t)
{
  //printf("yes");
  if(t==NULL)
  return 0;
  else
  {
    int h1 = getheight(t->left);
    int h2 = getheight(t->right);
    if(h1>h2)
    return h1+1;
    return h2+1;
  }
}

void printl(struct bst *t, int l)
{
  if(l==0)
  printf("%d\n",t->data);
  
  if(t->left!=NULL)
  printl(t->left, l-1);
  if(t->right!=NULL)
  printl(t->right, l-1);
}

void printlevel(struct bst *t)
{
  for(int i=0;i<getheight(t);i++)
  printl(t,i);
}