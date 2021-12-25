struct avl
{
  int key, height;
  struct avl *left, *right;
};

int getHeight(struct avl *n);
int max(int a, int b);
int getBalance(struct avl *n);
struct avl *leftR(struct avl *y);
struct avl *rightR(struct avl *x);
struct avl *createNode(int key);
struct avl *insert(struct avl *n, int key);
void inorder(struct avl *t);
void levelorder(struct avl *t);