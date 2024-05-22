typedef struct Queue Queue;
Queue* new_queue(int size);
void* dequeue(Queue* q);
void enqueue(Queue* q, void* data);
void print_queue(Queue *q);