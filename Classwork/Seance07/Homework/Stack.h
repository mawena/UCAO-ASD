#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct Item Item;
typedef struct Stack Stack;

struct Item{
    int number;
    Item *next;
};

struct Stack{
    Item *first;
};

Stack *initStack(int number);
void displayStack(Stack *stack);
void toStack(Stack *stack, int number);
void toRaise(Stack *stack, int number);
int toUnStack(Stack *stack);
void Stack_permut(Stack *stack, int numberPermut);

#endif // STACK_H_INCLUDED