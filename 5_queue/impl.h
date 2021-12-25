#include "adt.h"
#include<stdio.h>
#include<stdlib.h>


void init(struct q *qq, int maxs)
{
  qq->f = -1;
  qq->r = -1;
  qq->size = maxs;
}

int isFull(struct q *qq)
{
 if((qq->r == qq->size))
    return 1;
  return 0;
}

int isEmpty(struct q *qq)
{
  if(qq->f==-1)
  return 1;
  return 0;
}

void enqueue(struct q *qq, int value)
{
  if(!isFull(qq))  
  {
    qq->r++;
    qq->a[qq->r]=value;
  }
}

int dequeue(struct q *qq)
{
   qq->f++;
   if(!isEmpty(qq))
   return qq->a[qq->f];
}

void display(struct q *qq)
{
  int i = qq->f;
  //printf("%d@\n",i);
  for(i=0; i!=qq->r;i++)
  {
    printf("%d",qq->a[i]);
  }
  printf("%d\n",qq->a[i]);
}