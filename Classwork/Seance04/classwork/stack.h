#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct Item Item;
struct Item{
    int val;
    Item *next;
};

typedef struct Stack Stack
struct Stact{
    Item *first;
};

void toStack(Stack *stack, int v);

#endif // LINKEDLIST_H_INCLUDED
