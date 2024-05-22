#include <stdlib.h>
#include <stdio.h>
#include "ll.h"

struct Node{
  void* data;
  Node* next;
};

Node* new_node(void* data){
  Node* n = (Node*)calloc(1,sizeof(Node));
  n->data = data;
  return n;
}

struct LinkedList {
  Node* head;
};

LinkedList* new_linked_list(){
  return (LinkedList*)
  calloc(1,sizeof(LinkedList));
}

int size(LinkedList* ll){
  int result = 0;
  Node* p = ll->head;
  while (p){
    p=p->next;
    result++;
  }return result;
}

void print_ll(LinkedList* ll){
  Node* p = ll->head;
  printf("[");
  while (p){
    printf("%d", *(int *)p->data);
    p=p->next;
    if(p)
      printf(" , ");
  }
  printf("]\n");
}

int is_empty(LinkedList* ll) {
  return !ll->head;
}

void insert_at_front(LinkedList* ll, void* data){
  Node* n = new_node(data);
  if (!n) return;
  n->next = ll->head;
  ll->head = n;
}

void insert_at_back(LinkedList* ll, void* data){
  Node* n = new_node(data);
  if (!n) return;
  Node* p = ll->head;
  if (!p) ll->head = n;
  else {
    while (p->next) p=p->next;
    p->next = n;
  } 
}

void insert_after_nth(LinkedList* ll, void* data, int n){
  Node* nn = new_node(data);
  if (!nn) return;
  int i=0;
  Node* p = ll->head;
  if (!p) ll->head = nn;
  else {
    while (p->next && i < n){
      p = p->next; i++;
    }
    nn->next = p->next;
    p->next = nn;
  }
}

void insert_in_order(LinkedList* ll, void* data, int(*comp)(void*,void*)){
  Node* n = new_node(data);
  if (!n) return;
  Node* p = ll->head;
  if (!p || comp(data, p->data)<0){
    n->next = p;
    ll->head = n;
  }
  else {
    while (p->next && comp(data, p->next->data)>0) p=p->next;
    n->next = p->next;
    p->next = n;
  } 
}

void* remove_from_front(LinkedList*ll){
  void* result;
  Node* p = ll->head;
  if (!p) return NULL;
  result = p->data;
  ll->head = p->next;
  free(p);
  return result;
}

void* remove_from_back(LinkedList*ll){
  void* result;
  Node* p = ll->head;
  if (!p) return NULL;
  if (!(p->next)){
    result = p->data;
    ll->head = NULL;
    free(p);    
  } 
  else {
    while (p->next->next) p=p->next;
    result = p->next->data;
    free(p->next);
    p->next = NULL;
  }
  return result;
}