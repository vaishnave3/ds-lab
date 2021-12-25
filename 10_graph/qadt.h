struct q
{
  int data[100];
  int f, r, size;
};


int dequeue(struct q *c);
void enqueue(struct q *c, int x);
int isEmpty(struct q *c);
void init(struct q *c, int size);