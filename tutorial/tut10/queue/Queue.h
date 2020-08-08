// A queue datatype

struct queue *Queue;
struct node *Node;

Queue newQueue();

void addItem(Queue q, Item data);

Node removeItem(Queue q);
