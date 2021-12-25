#include "qadt.h"

void init(struct q *c, int size)
{
  c->f = -1;
  c->r = -1;
  c->size = size;
}

int isEmpty(struct q *c)
{
  if(c->r == c->f)
  return 1;
  return 0;
}

void enqueue(struct q *c, int x)
{
  c->r++;
  c->data[c->r] = x;
}

int dequeue(struct q *c)
{
  c->f++;
  return c->data[c->f]; 
}

