#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct Item Item;
typedef struct Stack Stack;

struct Item{
    char fixedPost;
    Item *next;
};

struct Stack{
    Item *first;
};

Stack *initStack(char fixedPost);
Stack *initNullStack();
void displayStack(Stack *stack);
void toStack(Stack *stack, char fixedPost);
void toRaise(Stack *stack, char fixedPost);
char toUnStack(Stack *stack);
Stack *inputStack();
int calcul(Stack *stack);
#endif // STACK_H_INCLUDED