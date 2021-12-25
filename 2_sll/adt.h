struct dll
{
  int data;
  struct dll *n;
};

struct dll *insert(struct dll *head, int x);
void display(struct dll *head);