#include "adt.h"
#include "qimpl.h"
#include<stdio.h>
#include<stdlib.h>

int visited[50];

void resetVisited(struct grp *s)
{
  for(int i=0;i<s->size;i++)
  visited[i]=0;
}

struct grp *createGraph(struct grp *s)
{
  int v, e;
  char edge[2];
  printf("Enter the number of vertices : ");
  scanf("%d",&v);
  s->size = v;
  for(int i=0; i<v; i++)
  {
    for(int j=0; j<v; j++)
    s->a[i][j] = 0;
  }

  printf("Enter no. of edges : ");
  scanf("%d", &e);
  for(int i=0; i<e;i++)
  {
    printf("Enter edge : ");
    scanf("%s", edge);
    s->a[(int)edge[0]-48][(int)edge[1]-48] = 1;
    s->a[(int)edge[1]-48][(int)edge[0]-48] = 1;
  }
  return s;
}

void display(struct grp *s)
{
  for(int i=0;i<s->size; i++)
  {
    for(int j=0;j<s->size;j++)
    printf("%d",s->a[i][j]);
    printf("\n");
  }
}


void bfs(struct grp *s)
{
  resetVisited(s);
  struct q *c = (struct q*)malloc(sizeof(struct q));
  for(int i=0;i<s->size;i++)
  {
    if(visited[i]==0)
    {
      init(c, s->size);
      enqueue(c, i);
      visited[i]=1;
      while(isEmpty(c)==0)
      {
        int u = dequeue(c);
        printf("%d ",u);
        for(int j=0;j<s->size;j++)
        {
          //printf(" @%d@ ", s->a[u][j]);
          if((visited[j]==0)&&(s->a[u][j]==1))
          {
            //printf("%d\n",j);
            visited[j]=1;
            enqueue(c,j);
          }
        }
      }
    }
  }
}


