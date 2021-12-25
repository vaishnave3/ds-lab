#include "impl.h"
#include<string.h>

int main()
{
    int ch=0, value;
    char str[10];
    struct bst *t = NULL;
    while(ch!=4)
    {
        printf("Enter the operation you want to perform : \n1. insert into bst \n2. display the bst (inorder) \n3. delete \n4. print level order \n5. exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter rollno you want to add : ");
            scanf("%d",&value);
            printf("Enter rollno you want to add : ");
            scanf("%s",str);
            t = insert(t,value,str);
        }
        else if(ch==2)
        {
            //printf("yes");
            inorder(t);
        }
        else if(ch==3)
        {
          printf("Enter element you want to add : ");
          scanf("%d",&value);
          del(t,value);
        }
        else if(ch==4)
        {
          printlevel(t);
        }
        else
        printf("Invalid choice.");
    }
    return 0;
}
