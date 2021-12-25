#include "impl.h"

int main()
{
  struct avl *root = (struct avl*)malloc(sizeof(struct avl));
  root = NULL;
  root = insert(root, 14);
  root = insert(root, 17);
  root = insert(root, 11);
  root = insert(root, 7);
  root = insert(root, 53);
  root = insert(root, 4);
  root = insert(root, 13);
  levelorder(root);
  return 0;
}