#include "impl.h"

int main()
{
  struct grp *s = (struct grp*)malloc(sizeof(struct grp));
  createGraph(s);
  display(s);
  bfs(s);
  return 0;
}