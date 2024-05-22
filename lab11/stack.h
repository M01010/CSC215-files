typedef struct Stack Stack;
Stack* new_stack(int size);
void* pop(Stack* s);
void push(Stack* s, void* data);
void* top(Stack *s);
void print_stack(Stack *s);
int is_stack_empty(Stack *s);