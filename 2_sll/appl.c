#include "impl.h"
int main()
{
  int ch=0, value;
  struct dll *head = (struct dll*)malloc(sizeof(struct dll));
  head = NULL;
  while(ch!=3)
  {
    printf("Enter your choice : \n1. enter an element \n2.display");
    scanf("%d",&ch);
    if(ch==1)
    {
      printf("Enter a number");
      scanf("%d",&value);
      head = insert(head,value);
    }
    else if(ch==2)
    {
      display(head);
    }
    else
    {
      printf("Invalid Choice.");
    }

  }
  return 0;
}
