#include "adt.h"
#include<stdlib.h>
#include<stdio.h>

struct dll *insert(struct dll *head, int x)
{
  struct dll *temp = (struct dll*)malloc(sizeof(struct dll));
  temp->data = x;
  if(head==NULL)
  {
    printf("yes");
    temp->n = NULL;
    head = temp;
  }
  else
  {
    printf("no");
    temp->n = head;
    head = temp;
  }
  return head;
}

void display(struct dll *head)
{
 // printf("%d",head->data);
  struct dll *temp;
  temp = head;
  while(temp->n != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->n;
  }
  printf("%d ",temp->data);
}