#include "queue.h"
#include "ll.h"
#include <stdlib.h>

struct Queue{
  LinkedList* buffer;
};

Queue* new_queue(int size){
  /* size is not needed*/
  Queue* result = (Queue*)calloc(1,sizeof(Queue));
  result->buffer = new_linked_list();
  return result;
}

void enqueue(Queue* q, void* data){
  insert_at_back(q->buffer, data);
}

void* dequeue(Queue* q){
  return remove_from_front(q->buffer);
}

void print_queue(Queue *q) {
  print_ll(q->buffer);
}

