#include "impl.h"

int main()
{
  int ch = 0, value;
  struct q qq;
  init(&qq,4);
  init(&qq,50);
  while(ch!=4)
  {
    printf("Enter your choice : \n1. enqueue \n2. dequeue");
    scanf("%d", &ch);
    if(ch==1)
    {
      printf("Enter the element you wanna add : ");
      scanf("%d",&value);
      enqueue(&qq,value);
    }
    else if(ch==2)
    {
       int x = dequeue(&qq);
       printf("deleted element is : %d ",x);
    }
    else
    printf("Invalid Choice");
  }
  return 0;
}