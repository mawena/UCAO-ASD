#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Stack *stack = initNullStack();
    toStack(stack, 'r');
    toStack(stack, '^');
    toStack(stack, '2');
    toStack(stack, '+');
    toStack(stack, '7');
    toStack(stack, '1');
    printf("La réponse est: %d\n", calcul(stack));
    // printf("%f", calcul(inputStack()));

    return 0;
}