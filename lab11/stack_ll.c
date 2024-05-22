#include <stdlib.h>
#include "ll.h"
#include "stack.h"

struct Stack{
  LinkedList* buffer;
};

int is_stack_empty(Stack *s){
  return is_empty(s->buffer);
}

void push(Stack* s, void* data){
  insert_at_front(s->buffer, data);
}

void* pop(Stack* s){
    return remove_from_front(s->buffer);
}

void* top(Stack* s){
    void *tmp;
    insert_at_front(s->buffer, tmp = remove_from_front(s->buffer));
    return tmp;
}

Stack* new_stack(int size){ /* size is not needed */
    Stack* result = (Stack*)calloc(1,sizeof(Stack));
    result->buffer = new_linked_list();
    return result;  
}

void print_stack(Stack *s){
  print_ll(s->buffer);
}