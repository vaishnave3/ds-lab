struct q
{
  int a[100];
  int f, r, size;
};


void display(struct q *qq);
int dequeue(struct q *qq);
void enqueue(struct q *qq, int value);
int isEmpty(struct q *qq);
int isFull(struct q *qq);
void init(struct q *qq, int maxs);