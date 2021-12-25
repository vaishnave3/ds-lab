struct bst 
{
    int data;
    char s[10];
    struct bst *left, *right;
};

struct bst *insert(struct bst *t, int x, char str[]);
struct bst *del(struct bst *t, int x);
void inorder(struct bst *t);
struct bst *findmin(struct bst *t);
int getheight(struct bst *t);
void printl(struct bst *t, int l);
void printlevel(struct bst *t);


