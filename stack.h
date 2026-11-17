#ifndef STACK_H
#define STACK_H

#include "global.h"

typedef struct {
    element_type items[MAX_SIZE];
    int top;
} Stack;

void CreateStack(Stack *s);
int  StackEmpty(const Stack *s);
int  StackFull(const Stack *s);
int  Push(element_type e, Stack *s);
int  Pop(element_type *e, Stack *s);

#endif
