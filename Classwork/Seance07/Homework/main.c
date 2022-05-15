#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(){
    Stack *stack = initStack(0);
    toStack(stack, 1);
    toStack(stack, 2);
    toStack(stack, 3);
    toStack(stack, 4);
    toStack(stack, 5);
    Stack_permut(stack, 3);
    displayStack(stack);

    return 0;
}