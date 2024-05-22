#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char author[50];
    int version;
} Book;
struct node {
    void *data;
    struct node *next;
};
typedef struct node Node;
typedef struct {
    Node *head;
} LinkedList;

Node *new_node(void *data) {
    Node *n = (Node *)calloc(1, sizeof(Node));
    n->data = data;
    return n;
}
LinkedList *new_linked_list() {
    return (LinkedList *)calloc(1, sizeof(LinkedList));
}
void addFirst(LinkedList *l, void *data) {
    Node *n = new_node(data);
    if (!n) return;
    n->next = l->head;
    l->head = n;
}
void addLast(LinkedList *l, void *data) {
    Node *n = new_node(data);
    if (!n) return;
    if (!l->head) {
        l->head = n;
        return;
    }

    Node *current = l->head;
    while (current->next) {
        current = current->next;
    }
    current->next = n;
}
void *removeFirst(LinkedList *l) {
    Node *n = l->head;
    if (!n) return NULL;
    void *result = n->data;
    l->head = l->head->next;
    free(n);
    return result;
}
void printLinkedList(LinkedList l) {
    Node *n = l.head;
    while (n) {
        Book *b = (Book *)n->data;
        printf("Book ID: %d, Author: %s, version: %d\n", b->id, b->author,
               b->version);
        n = n->next;
    }
}
int size(LinkedList l) {
    int size = 0;
    Node *n = l.head;
    while (n) {
        n = n->next;
        size++;
    }
    return size;
}
void *deleteBook(LinkedList *l, int bookID) {
    if (!l->head) {
        printf("Couldnt delete book with id %d\n", bookID);
        return NULL;
    }
    Book *result = (Book *)l->head->data;
    if (result->id == bookID) {
        Node *p = l->head;
        l->head = l->head->next;
        free(p);
        return result;
    }
    Node *n = l->head;
    while (n->next) {
        Node *p = n->next;
        result = (Book *)p->data;
        if (result->id == bookID) {
            n->next = p->next;
            free(p);
            return result;
        }
        n = n->next;
    }
    printf("Couldnt delete book with id %d\n", bookID);
    return NULL;
}
void reverseList(LinkedList *l) {
    LinkedList *stack = new_linked_list();
    if (!stack) return;
    while (l->head) {
        void *data = removeFirst(l);
        addFirst(stack, data);
    }
    while (stack->head) {
        void *data = removeFirst(stack);
        addLast(l, data);
    }
    free(stack);
}
int main() {
    LinkedList *l = new_linked_list();
    deleteBook(l, 0);
    Book b1 = {123, "ahmad", 1};
    Book b2 = {456, "mohammed", 3};
    Book b3 = {789, "abdullah", 2};
    Book b4 = {376, "ali", 5};
    addLast(l, &b1);
    addLast(l, &b2);
    addLast(l, &b3);
    addFirst(l, &b4);
    printLinkedList(*l);
    Book *b = (Book *)deleteBook(l, 789);
    if (b) {
        printf("Deleted book with id: %d\n", b->id);
    }
    b = (Book *)deleteBook(l, 999);

    printf("reversing list\n");
    reverseList(l);
    printLinkedList(*l);

    printf("size of list:%d \n", size(*l));
    return 0;
}