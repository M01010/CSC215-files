#include "queue.h"
void reverse(Queue *q)
{
    int *x = dequeue(q);
    if (!x)
    {
        return;
    }
    reverse(q);
    enqueue(q, x);
}
int main()
{
    Queue *q = new_queue(20);
    int a = 1;
    enqueue(q, &a);
    int b = 2;
    enqueue(q, &b);
    int c = 3;
    enqueue(q, &c);


    print_queue(q); /*need to implement print_queue to show the queue*/
    reverse(q);
    print_queue(q);
    return 0;
}