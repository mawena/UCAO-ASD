#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

// Init a stack
Stack *initStack(int number) {
  Stack *stack = malloc(sizeof(*stack));
  Item *firstItem = malloc(sizeof(*firstItem));
  if (stack == NULL || firstItem == NULL) {
    return 0;
  } else {
    firstItem->number = number;
    firstItem->next = NULL;
    stack->first = firstItem;
    return stack;
  }
}

// Display a stack
void displayStack(Stack *stack) {
  if (stack == NULL) {
    return;
  } else {
    Item *current = stack->first;
    while (current != NULL) {
      printf("|%d|\n", current->number);
      current = current->next;
    }
    printf("---\n");
  }
}

// Stack a value in a stack
void toStack(Stack *stack, int number) {
  Item *item = malloc(sizeof(*item));
  if (stack == NULL || item == NULL) {
    return;
  } else {
    item->number = number;
    item->next = stack->first;
    stack->first = item;
  }
}

// Unstack the first value of a stack
int toUnStack(Stack *stack) {
  if (stack == NULL) {
    return 0;
  } else {
    Item *current = stack->first;
    int value = current->number;
    stack->first = current->next;
    free(current);
    return value;
  }
}

// insert a value at the down of a stack
void toRaise(Stack *stack, int number) {
  Item *item = malloc(sizeof(*item));
  if (stack == NULL || item == NULL) {
    return;
  } else {
    Item *current = stack->first;
    while (current->next != NULL) {
      current = current->next;
    }

    item->number = number;
    item->next = NULL;
    current->next = item;
  }
}


// Permut a stack
void Stack_permut(Stack *stack, int numberPermut) {
  if (stack == NULL) {
    return;
  } else {
    while (numberPermut > 0) {
      toRaise(stack, toUnStack(stack));
      numberPermut--;
    }
  }
}

// Permut reversly a stack
void StackPermutReverse(Stack *stack, int numberPermut) {
  if (stack == NULL) {
    return;
  } else {
  }
}