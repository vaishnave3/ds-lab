
struct grp
{
  int a[50][50];
  int size;
};

struct grp *createGraph(struct grp *s);
void display(struct grp *s);
void bfs(struct grp *s);
void resetVisited(struct grp *s);