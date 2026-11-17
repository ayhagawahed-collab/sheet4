
#include "stack.h"

void CreateStack(Stack *s) {
    s->top = -1;
}

int StackEmpty(const Stack *s) {
    return s->top == -1;
}

int StackFull(const Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int Push(element_type e, Stack *s) {
    if (StackFull(s)) return 0;
    s->items[++s->top] = e;
    return 1;
}

int Pop(element_type *e, Stack *s) {
    if (StackEmpty(s)) return 0;
    *e = s->items[s->top--];
    return 1;
}
