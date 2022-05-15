#include "Stack.h"
#include "string.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Init a stack
Stack *initStack(char fixedPost) {
  Stack *stack = malloc(sizeof(*stack));
  Item *firstItem = malloc(sizeof(*firstItem));
  if (stack == NULL || firstItem == NULL) {
    exit(0);
  } else {
    firstItem->fixedPost = fixedPost;
    firstItem->next = NULL;
    stack->first = firstItem;
    return stack;
  }
}

Stack *initNullStack() {
  Stack *stack = malloc(sizeof(*stack));
  if (stack == NULL) {
    exit(0);
  } else {
    stack->first = NULL;
    return stack;
  }
}

// Display a stack
void displayStack(Stack *stack) {
  if (stack == NULL) {
    return;
  } else {
    Item *current = stack->first;
    printf("\n");
    while (current != NULL) {
      printf("|%c|\n", current->fixedPost);
      current = current->next;
    }
    printf("|||\n");
  }
}

// Stack a value in a stack
void toStack(Stack *stack, char fixedPost) {
  Item *item = malloc(sizeof(*item));
  if (stack == NULL || item == NULL) {
    return;
  } else {
    item->fixedPost = fixedPost;
    item->next = stack->first;
    stack->first = item;
  }
}

// Unstack the first value of a stack
char toUnStack(Stack *stack) {
  if (stack == NULL) {
    exit(0);
  } else {
    Item *current = stack->first;
    char value = current->fixedPost;
    stack->first = current->next;
    free(current);
    return value;
  }
}

// insert a value at the down of a stack
void toRaise(Stack *stack, char fixedPost) {
  int d;
  Item *item = malloc(sizeof(*item));
  if (stack == NULL || item == NULL) {
    return;
  } else {
    Item *current = stack->first;
    while (current->next != NULL) {
      current = current->next;
    }

    item->fixedPost = fixedPost;
    item->next = NULL;
    current->next = item;
  }
}

Stack *inputStack() {
  int n;
  do {
    printf("Entrez le nombre de caractère de l'expression:");
    scanf("%d", &n);
  } while (n < 1);

  char fixedPost[n];
  printf("Entrez l'expression: ");
  scanf("%s", fixedPost);

  Stack *stack = initStack(fixedPost[0]);
  int comp = 1;
  while (fixedPost[comp] != '\0') {
    toRaise(stack, fixedPost[comp]);
    comp++;
  }
  return stack;
}

int calcul(Stack *stack) {
  Stack *secondStack = initNullStack();

  if (stack == NULL || secondStack == NULL) {
    exit(0);
  } else {
    while (stack->first != NULL) {
      toStack(secondStack, (char)toUnStack(stack));

      Item *currentItem = secondStack->first;
      if (currentItem->fixedPost == '+' || currentItem->fixedPost == '-' ||
          currentItem->fixedPost == '*' || currentItem->fixedPost == '/' ||
          currentItem->fixedPost == '^' || currentItem->fixedPost == 'r') {

        if (currentItem->next == NULL) {
          if (currentItem->fixedPost == 'r') {
            char operator= toUnStack(secondStack);
            int value = (int)toUnStack(secondStack) - 48;
            toStack(stack, (char)((int)sqrt(value)) + '0');
          } else {
            exit(0);
          }
        } else {
          char operator= toUnStack(secondStack); // On retire tire l'opérateur
          int first = (int)toUnStack(secondStack) -
                      48; // On retire le dernier élément de la pile
          if (operator== 'r') {
            toStack(stack, (char)((int)sqrt(first)) + '0');
          } else {
            int second = (int)toUnStack(secondStack) -
                         48; // On retire le nouveau dernier élément de pile
            if (operator== '+') {
              toStack(secondStack, (char)(second + first) + '0');
            } else if (operator== '-') {
              toStack(secondStack, (char)(second - first) + '0');
            } else if (operator== '*') {
              toStack(secondStack, (char)(second * first) + '0');
            } else if (operator== '/') {
              toStack(secondStack, (char)(second / first) + '0');
            } else if (operator== '^') {
              toStack(secondStack, (char)(pow(second, first) + '0'));
            }
          }
        }
      }
    }
    return (int)toUnStack(secondStack) - 48;
  }
  exit(0);
}